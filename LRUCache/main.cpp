#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){}
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){}
};

class Cache{

   protected:
   map<int, Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};

class LRUCache : public Cache{
public:
    LRUCache(int capacity){
        cp = capacity;
        head = tail = nullptr;
    }

    void set(int key, int value) override {

        if(head == nullptr){
            Node *node = new Node(key, value);
            head = tail = node;
            mp[key] = node;
        }
        else{
            auto aa = mp.find(key);

            // if the key already exists in the list
            if(aa != mp.end()){

                auto found_node = aa->second;

                found_node->value = value;

                if(found_node->prev)
                    found_node->prev->next = found_node->next;

                found_node->prev = head->prev;
                found_node->next = head;
                head = found_node;
            }
            else{

                if(mp.size() < cp -1){
                    Node* node;

                    if(head){
                        node = new Node(head->prev, head->next, key, value);
                    }else{
                        node = new Node(key, value);
                    }

                    head = node;
                    mp[key] = node;
                }
                else{
                    auto temp_tail = tail;
                    tail = tail->prev;

                    Node* node;

                    if(head){
                        node = new Node(head->prev, head->next, key, value);
                    }else{
                        node = new Node(key, value);
                    }

                    head = node;
                    mp[key] = node;
                    delete temp_tail;
                }
            }
        }
    }

    int get(int key) override {

        auto aa = mp.find(key);

        if(aa == mp.end()){
            return -1;
        }else{

            auto found_node = aa->second;
            if(found_node->prev)
                found_node->prev->next = found_node->next;
            found_node->prev = head->prev;
            found_node->next = head;
            head = found_node;
            return head->value;
        }
    }
};

int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      }
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}

