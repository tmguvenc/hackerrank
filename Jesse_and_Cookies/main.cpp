#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main() {

    std::priority_queue<int, vector<int>, greater<int>> queue;

    int cookie_count, min_sweetness;
    cin >> cookie_count >> min_sweetness;

    for(int i = 0; i < cookie_count; ++i) {
        int val; cin >> val;
        queue.push(val);
    }

    int op_count = 0;

    while(true){
        int min = queue.top(); queue.pop();
        int second_min = queue.top(); queue.pop();

        if(min >= min_sweetness) break;

        auto sw = min + (second_min * 2);
        op_count++;

        queue.push(sw);

        if(queue.size() < 2 && queue.top() < min_sweetness){
            op_count = -1;
            break;
        }
    }

    cout << op_count;

    return 0;
}
