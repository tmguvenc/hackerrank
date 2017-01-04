#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

template<typename T>
class MyQueue{
public:
    MyQueue() { }
    ~MyQueue() { }

    void enqueue(const T& item){
        newest_stack.push(item);
    }

    const T& top() {
        shift();
        return oldest_stack.top();
    }

    void dequeue(){
        shift();
        oldest_stack.pop();
    }

private:
    void shift(){
        if(oldest_stack.empty()){
            while(!newest_stack.empty()){
                oldest_stack.push(newest_stack.top());
                newest_stack.pop();
            }
        }
    }

private:
    stack<T> newest_stack, oldest_stack;
};

int main() {

    int count; cin >> count;
    MyQueue<int> q;
    for(int i = 0; i < count; ++i){
        int command; cin >> command;
        if(command == 1){
            int val; cin >> val;
            q.enqueue(val);
        }else if(command == 2){
            q.dequeue();
        }else if(command == 3){
            cout << q.top() << endl;
        }
    }

    return 0;
}
