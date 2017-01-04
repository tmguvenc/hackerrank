#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

struct MyStruct{
    int max;
    int val;
};

int main() {

    int query_count; cin >> query_count;

    stack<MyStruct> st;

    int current_max = -INT32_MAX;

    for(int i = 0; i < query_count; ++i){

        int command; cin >> command;

        if(command == 1){
            int val; cin >> val;
            current_max = val > current_max ? val : current_max;
            st.push({current_max, val});
        }
        else if(command == 2){
            if(!st.empty())
                st.pop();
            current_max = st.empty() ? -INT32_MAX : st.top().max;
        }
        else if(command == 3){
            if(!st.empty())
                cout << st.top().max << endl;
        }
    }

    return 0;
}
