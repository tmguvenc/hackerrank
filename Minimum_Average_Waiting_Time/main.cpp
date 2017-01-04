#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

using MyType = pair<int, int>;

struct MyTypeGreater{
    bool operator()(const MyType& p1, const MyType& p2){
        return p1.second > p2.second;
    }
};

using MinPQ = priority_queue<MyType, vector<MyType>, MyTypeGreater>;

int main() {

    MinPQ queue;

    int count; cin >> count;

    for(int i = 0; i < count; ++i){

        int arr_time, cook_time;
        cin >> arr_time >> cook_time;

        queue.push(make_pair(arr_time, cook_time));
    }

    int avg = 0;
    int cook_sum = 0;

    auto size = queue.size();

    while(!queue.empty()){
        const auto &top = queue.top();
        cook_sum += top.second;
        avg += cook_sum - top.first;
        queue.pop();
    }

    cout << avg / size;

    return 0;
}
