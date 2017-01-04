#include <iostream>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;

#define RESERVED -INT32_MAX

template<typename T>
class MinPQ{
public:
    MinPQ() { m_queue.push_back(RESERVED);}

    void push(const T& item){
        m_queue.push_back(item);
        swim(m_queue.size() - 1);
    }

    T top(){
        T min = m_queue[1];
        swap(m_queue[1], m_queue.back());
        m_queue.pop_back();
        sink(1);
        return min;
    }

    void del(const T& item){
        if(item != m_queue[1]){
            delete_map.insert(make_pair(item, 0));
        }
        else{
            swap(m_queue[1], m_queue.back());
            m_queue.pop_back();
            sink(1);
        }
    }

protected:
    void swim(int index){
        while(index > 1 && greater(index/2, index)){
            std::swap(m_queue[index], m_queue[index / 2]);
            index = index / 2;
        }
    }
    void sink(int index){
        while(2*index <= m_queue.size() - 1){
            int j = 2*index;
            if(j < m_queue.size() && greater(j, j+1)) j++;
            if(!greater(index, j)) break;
            swap(m_queue[index], m_queue[j]);
            index = j;
        }
    }
    bool greater(int index1, int index2){
        return m_queue[index1] > m_queue[index2];
    }

public:
    map<int, int> delete_map;

private:
    std::deque<T> m_queue;
};

int main(int argc, char *argv[])
{
    priority_queue<int, vector<int>, greater<int>> queue;
    //MinPQ<int> queue;
    map<int, int> deletion;

    int temp; cin >> temp;

    for(int i = 0; i < temp; ++i){
        int command;
        cin >> command;

        if(command == 1){
             int value; cin >> value;
            queue.push(value);
        }
        else if(command == 2){
            int value; cin >> value;

            if(value == queue.top()){
                queue.pop();
            }
            else{
                deletion.insert(make_pair(value, 0));
            }
        }
        else if(command == 3){
            while(true){
                auto top = queue.top();
                auto aa = deletion.find(top);

                if(aa == deletion.end()){
                    cout << top << endl;
                    break;
                }
                else
                {
                    queue.pop();
                    deletion.erase(aa);
                }
            }
        }
    }

    return 0;
}
