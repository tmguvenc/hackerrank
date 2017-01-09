#include <iostream>
#include <memory.h>

using namespace std;

void mergehalves(int arr[], int temp[], int left_start, int right_end, int middle){
    int left_index = left_start;
    int right_index = middle + 1;
    int temp_index = left_start;
    int left_end = middle;

    while(left_index <= left_end && right_index <= right_end){
        if(arr[left_index] <= arr[right_index]){
            temp[temp_index++] = arr[left_index++];
        }else{
            temp[temp_index++] = arr[right_index++];
        }
    }

    while(left_index <= left_end)
        temp[temp_index++] = arr[left_index++];
    while(right_index <= right_end)
        temp[temp_index++] = arr[right_index++];

    for(int i = left_start; i <= right_end; ++i)
        arr[i] = temp[i];
}

void mergesort(int arr[], int temp[], int left_start, int right_end){
    if(left_start >= right_end) return;
    int middle = (left_start + right_end) / 2;
    mergesort(arr, temp, left_start, middle);
    mergesort(arr, temp, middle + 1, right_end);
    mergehalves(arr, temp, left_start, right_end, middle);
}

void mergesort(int arr[], int size){
    int temp[1000] = {0};
    mergesort(arr, temp, 0, size - 1);
}

int main(int argc, char *argv[])
{
    int arr[] = {9,8,7,6,5,4,3,2,1};
    int size = sizeof(arr) / sizeof(int);

    mergesort(arr, size);

    for(auto a : arr){
        cout << a << " ";
    }

    cout << endl;
    return 0;
}
