#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main() {

    int h[3];
    cin >> h[0] >> h[1] >> h[2];

    int min_idx = h[0] < h[1] ? 0 : 1;
    min_idx = h[2] < h[min_idx] ? 2 : min_idx;

    stack<int> st;
    vector<int> arr[2];

    auto current_index = 0;

    for(int i = 0; i < 3; ++i){
        stack<int> temp_stack;
        for(int j = 0; j < h[i]; ++j){
            int temp; cin >> temp;
            temp_stack.push(temp);
        }

        if(i != min_idx){
            arr[current_index].push_back(temp_stack.top());
            temp_stack.pop();
            while(!temp_stack.empty()){
                arr[current_index].push_back(arr[current_index].back() + temp_stack.top());
                temp_stack.pop();
            }
            current_index++;
        }
        else{
            while(!temp_stack.empty()){
                auto temp = temp_stack.top();
                temp_stack.pop();
                if(st.empty())
                    st.push(temp);
                else
                    st.push(st.top() + temp);
            }
        }
    }

    while(!st.empty()){

        auto curr = st.top();
        bool found = false;

        auto index1 = arr[0].size() - 1;
        auto index2 = arr[1].size() - 1;

        for(; index1 >= 0 && index2 >= 0;){
            if(curr > arr[0][index1] || curr > arr[1][index2]){
                st.pop();
                found = false;
                break;
            }
            else {
                if(curr < arr[0][index1]){
                    index1--;
                }
                if(curr < arr[1][index2]){
                    index2--;
                }

                if(curr == arr[0][index1] && curr == arr[1][index2]){
                    found = true;
                    break;
                }
            }
        }

        if(found){
            cout << curr;
            break;
        }

        if(st.empty() && !found){
            cout << "0";
            break;
        }
    }

    cout.flush();
    return 0;
}
