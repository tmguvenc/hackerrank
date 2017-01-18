#include <iostream>

using namespace std;

/*
 * Given an array of n distinct integers sorted in ascending order,
 * write a function that returns a Fixed Point in the array,
 * if there is any Fixed Point present in array, else returns -1.
 * Fixed Point in an array is an index i such that arr[i] is equal to i.
 * Note that integers in array can be negative.
*/

int find_fixed_point(int arr[], int left, int right){
    if(left > right)
        return -1;

    int middle = left + (right - left) / 2;

    if(middle == arr[middle])
        return middle;

    if(middle > arr[middle])
        return find_fixed_point(arr, middle + 1, right);

    return find_fixed_point(arr, left, middle);
}

int find_fixed_point(int arr[], int size){
    return find_fixed_point(arr, 0, size - 1);
}

int main(int argc, char *argv[])
{
    int arr[] = {-10, -1, 0, 3, 10, 11, 30, 50, 100};
    int size = sizeof(arr)/sizeof(arr[0]);

    int index = find_fixed_point(arr, size);
    if(index == -1){
        cout << "not found" << endl;
    }else{
        cout << "at index " << index << ": " << arr[index] << endl;
    }

    return 0;
}
