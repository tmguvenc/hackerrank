#include <iostream>
#include <limits>
#include <map>

using namespace std;

/*
 * Given a sorted array and a number x, find the pair in array whose sum is closest to x
*/

pair<int, int> find_closest_index(int arr[], int size, int x){

    int lo = 0;
    int hi = size - 1;

    int min_delta = std::numeric_limits<int>::max();
    int x_lo = -1, x_hi = -1;

    while(lo < hi){
        int sum = arr[lo] + arr[hi];
        int delta = std::abs(sum - x);

        if(delta < min_delta){
            min_delta = delta;
            x_lo = lo;
            x_hi = hi;
        }

        if(delta == 0){
            // we found the exact match
            x_lo = lo;
            x_hi = hi;
            break;
        }else if(sum < x){
            lo++;
        }else{
            hi--;
        }
    }

    return make_pair(x_lo, x_hi);
}

int main(int argc, char *argv[])
{
    int arr[] = { 1, 3, 4, 7, 10 };
    int size = sizeof(arr) / sizeof(int);

    auto indexes = find_closest_index(arr, size, 15);

    cout << "[" << arr[indexes.first] << ", " << arr[indexes.second] << "]" << endl;

    return 0;
}
