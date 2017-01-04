#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

struct Plant{
    int val;
    bool kill;
};

int main() {

    int count; cin >> count;

    stack<Plant> stack;

    int maxDays = 0;
    int days = 0;
    int temp; cin >> temp;

    stack.push({temp, false});

    for(int i = 1; i < count; ++i){
        int temp; cin >> temp;

        auto top = stack.top();
        if(top.val >= temp){

            if(top.kill){
                stack.pop();
                days++;
                if(days > maxDays)
                    maxDays = days;
            }
            else{
                if(days > 0) days--;
            }
            stack.push({temp, false});
        }
        else{
            if(top.kill){
                stack.pop();
                days++;
                if(days > maxDays)
                    maxDays = days;
            }
            else{
                if(days > 0) days--;
            }
            stack.push({temp, true});
        }
    }

    cout << maxDays;
    return 0;
}
