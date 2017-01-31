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

using namespace std;

long long count_merge(vector<int>& arr, vector<int>& temp, int left_start, int right_end, int middle){
    int left_index = left_start;
    int right_index = middle + 1;
    int temp_index = left_start;
    int left_end = middle;

    int count = 0;
    while(left_index <= left_end && right_index <= right_end){
        if(arr[left_index] <= arr[right_index]){
            temp[temp_index++] = arr[left_index++];
        }else{
            temp[temp_index++] = arr[right_index++];
            count += middle + 1 - left_index;
        }
    }

    while(left_index <= left_end)
        temp[temp_index++] = arr[left_index++];
    while(right_index <= right_end)
        temp[temp_index++] = arr[right_index++];

    for(int i = left_start; i <= right_end; ++i)
        arr[i] = temp[i];

    return count;
}

long long count_inversions(vector<int>& a, vector<int>& temp, int left, int right){
    if(left >= right)
        return 0;

    int middle = left + (right - left) / 2;

    int count = 0;
    count += count_inversions(a, temp, left, middle);
    count += count_inversions(a, temp, middle + 1, right);
    count += count_merge(a, temp, left, right, middle);

    return count;
}

long long count_inversions(vector<int> a) {
    vector<int> temp(a.size());
    return count_inversions(a, temp, 0, a.size() - 1);
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int arr_i = 0;arr_i < n;arr_i++){
            cin >> arr[arr_i];
        }
        cout << count_inversions(arr) << endl;
    }
    return 0;
}
