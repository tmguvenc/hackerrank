#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main() {

    int N, Q;
    cin >> N >> Q;

    deque<int> queue;

    for(int i = 0; i < N; ++i) {
        int temp; cin >> temp;
        queue.push_back(temp);
    }

    for(int i = 0; i < Q; ++i){

        auto temp = queue.front();
        queue.pop_front();
        queue.push_back(temp);
    }

    for(int i = 0; i < N; ++i)
        cout << queue[i] << " ";

    return 0;
}
