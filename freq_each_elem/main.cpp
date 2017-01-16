#include <iostream>
#include <unordered_map>

using namespace std;

/*
 * Find frequency of each element in a limited range array in less than O(n) time.
 *
 * Given an sorted array of positive integers, count number of occurrences for each element in the array. Assume all elements in the array are less than some constant M.
 *
 * Do this without traversing the complete array. i.e. expected time complexity is less than O(n).
 *
 * algorithmic complexity = O(m log n), where m is the count of distinct elements
 *
*/

void freq(int arr[], int left, int right, unordered_map<int, int>& s){
    if(arr[left] == arr[right]){
        s[arr[left]] += right - left + 1;
        return;
    }

    int middle = left + (right - left) / 2;

    freq(arr, left, middle, s);
    freq(arr, middle + 1, right, s);
}

void freq(int arr[], int size){
    unordered_map<int, int> s;
    freq(arr, 0, size - 1, s);
    for(auto it = s.begin(); it != s.end(); ++it){
        cout << it->first << ": " << it->second << endl;
    }
}

int main(int argc, char *argv[])
{
    int arr[] = { 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 5,
                  5,5,5,5,5, 8, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 10, 10, 10 };
    int size = sizeof(arr) / sizeof(arr[0]);

    freq(arr, size);

    return 0;
}
