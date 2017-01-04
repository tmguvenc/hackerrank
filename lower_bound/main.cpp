#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int count; cin >> count;
    vector<int> vec;
    for(int i = 0; i < count; ++i){
        int temp; cin >> temp;
        vec.push_back(temp);
    }

    int query_count; cin >> query_count;

    for(int i = 0; i < query_count; ++i){
        int num; cin >> num;

        auto lb = std::lower_bound(vec.begin(), vec.end(), num);

        auto pos = lb - vec.begin();

        if(vec[pos] == num){
            cout << "Yes " << pos + 1 << endl;
        }
        else{
            cout << "No " << pos + 1 << endl;
        }
    }

    return 0;
}
