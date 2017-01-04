#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <assert.h>

using namespace std;

using MinPQ = priority_queue<int, vector<int>, greater<int>>;
using MaxPQ = priority_queue<int, vector<int>, less<int>>;

inline void print(const MaxPQ& maxQueue, const MinPQ& minQueue){

    double result = ((maxQueue.size() + minQueue.size()) % 2 == 0) ?
                static_cast<double>(maxQueue.top() + minQueue.top()) / 2.0 :
                (maxQueue.size() > minQueue.size()) ?
                    static_cast<double>(maxQueue.top()) :
                    (maxQueue.size() < minQueue.size()) ?
                        static_cast<double>(minQueue.top()) :
                        INT64_MIN;

    printf("%.1f\n", result);
}

template<typename Q1, typename Q2>
inline void move(Q1& from, Q2& to){
    auto temp = from.top();
    to.push(temp);
    from.pop();
}

template<typename Q1, typename Q2>
inline void balance(Q1& q1, Q2& q2){
    while(true){
        auto q1size = static_cast<int>(q1.size());
        auto q2size = static_cast<int>(q2.size());

        if(q2size - q1size > 1)
            move(q2, q1);
        else if(q1size - q2size > 1)
            move(q2, q2);
        else
            break;
    }
}

int main() {

    MinPQ min_queue;
    MaxPQ max_queue;

    int count; cin >> count;

    for(int i = 0; i < count; ++i){
        int temp; cin >> temp;

        if(min_queue.empty()){
            min_queue.push(temp);
            print(max_queue, min_queue);
            continue;
        }
        if(max_queue.empty()){
            if(temp > min_queue.top()){
                move(min_queue, max_queue);
                min_queue.push(temp);
            }
            else
                max_queue.push(temp);

            print(max_queue, min_queue);
            continue;
        }

        if(temp < min_queue.top()){
            if(max_queue.empty()){
                max_queue.push(temp);
            }
            else if(temp < max_queue.top()){
                max_queue.push(temp);
                if(max_queue.size() > min_queue.size()){
                    move(max_queue, min_queue);
                }
            }
            else{
                min_queue.push(temp);
            }
        }
        else if(temp >= max_queue.top()){
            if(temp < min_queue.top()) {
                printf("%.1f\n", static_cast<double>(temp));
                max_queue.push(temp);
            }
            else{
                min_queue.push(temp);
                if(min_queue.size() > max_queue.size()){
                    move(min_queue, max_queue);
                }
            }
        }
        else{
            cout << "###########################################" << endl;
        }

        balance(max_queue, min_queue);

        print(max_queue, min_queue);
    }

    return 0;
}
