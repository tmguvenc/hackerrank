#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

using IntVector = vector<int>;

int main() {

    int N, Q;
    cin >> N >> Q;

    vector<IntVector> seqList(N);

    int lastAns = 0;

    for(int i = 0; i < Q; ++i){

        int command, x, y;

        cin >> command >> x >> y;

        auto index = (x ^ lastAns) % N;

        if(command == 1){
            seqList[index].push_back(y);
        }
        else if(command == 2){
            lastAns = seqList[index][y%seqList[index].size()];
            cout << lastAns << endl;
        }
    }

    return 0;
}
