#include <iostream>

using namespace std;

int ceiling(int arr[], int left, int right, int x){
    if(left > right)
        return -1;

    int middle = left + (right - left) / 2;

    if(middle == 0 || x == arr[middle])
        return middle;

    if(x > arr[middle] && x < arr[middle + 1])
        return middle + 1;

    if(x < arr[middle])
        return ceiling(arr, left, middle - 1, x);

    return ceiling(arr, middle + 1, right, x);
}

int ceiling(int arr[], int size, int x){
    return ceiling(arr, 0, size - 1, x);
}

int main(int argc, char *argv[])
{
    int arr[] = {1, 2, 8, 10, 10, 12, 19};
    int size = sizeof(arr) / sizeof(arr[0]);

    int ceiling_index = ceiling(arr, size, 1);

    cout << "index: " << ceiling_index << endl;

    return 0;
}
