#include <iostream>

using namespace std;

int find_min(int arr[], int size){
    if(size < 2)
        return std::min(arr[0], arr[1]);

    if(arr[0] > arr[size/2])
        return find_min(arr, size / 2);
    else
        return find_min(arr + size / 2, size - size / 2);
}

int main(int argc, char *argv[])
{
    int arr[] = {  5, 6, 7, 1, 2, 3, 4, };

    auto len = sizeof(arr) / sizeof(int);

    if(arr[0] > arr[len - 1])
        cout << find_min(arr, len) <<  endl;

    return 0;
}
