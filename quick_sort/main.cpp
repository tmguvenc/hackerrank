#include <iostream>

using namespace std;

void swap(int arr[], int idx1, int idx2){
    auto temp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;
}

int partition(int arr[], int left, int right, int pivot){
    while(left <= right){
        while(arr[left] < pivot){
            left++;
        }
        while(arr[right] > pivot){
            right--;
        }

        if(left <= right){
            swap(arr, left++, right--);
        }
    }
    return left;
}

void quicksort(int arr[], int left, int right){
    if(left >= right) return;
    int pivot = arr[(left + right)/2];
    int partition_point = partition(arr, left, right, pivot);
    quicksort(arr, left, partition_point - 1);
    quicksort(arr, partition_point, right);
}

void quicksort(int arr[], int size){
    quicksort(arr, 0, size - 1);
}

int main(int argc, char *argv[])
{
    int arr[] = {9,8,7,6,5,4,3,2,1};
    int size = sizeof(arr) / sizeof(int);
    quicksort(arr, size);

    for(auto c : arr)
        cout << c << " ";

    cout << endl;
    return 0;
}
