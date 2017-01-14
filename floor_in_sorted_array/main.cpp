#include <iostream>

using namespace std;

int floor(int arr[], int left, int right, int value){

    if(left > right)
        return -1;

    if(value >= arr[right])
        return right;

    int middle = left + (right - left) / 2;

    if(value == arr[middle])
        return middle;

    if(arr[middle - 1] < value && arr[middle] > value)
        return middle - 1;

    if(value > arr[middle])
        return floor(arr, middle + 1, right, value);

    return floor(arr, left, middle - 1, value);
}

int floor(int arr[], int size, int value){
    return floor(arr, 0, size - 1, value);
}

int main(int argc, char *argv[])
{
    int arr[] = {1, 2, 4, 6, 10, 12, 14};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "index: " << floor(arr, size, 5) << endl;
    return 0;
}
