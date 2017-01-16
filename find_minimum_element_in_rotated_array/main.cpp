#include <iostream>

using namespace std;

int find_min(int arr[], int left, int right){
    if(left >= right)
        return left;

    int middle = left + (right - left) / 2;

    if(middle < right && arr[middle] > arr[middle + 1])
        return middle + 1;

    if(middle > left && arr[middle] < arr[middle - 1])
        return middle;

    if(arr[middle] > arr[right])
        return find_min(arr, middle + 1, right);

    return find_min(arr, left, middle - 1);
}

int find_min(int arr[], int size){
    return find_min(arr, 0, size - 1);
}

int main(int argc, char *argv[])
{
    int arr[] = {  3, 4, 5, 6, 7, 1, 2, };
    auto len = sizeof(arr) / sizeof(int);
    cout << find_min(arr, len) <<  endl;
    return 0;
}
