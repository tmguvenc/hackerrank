#include <iostream>

using namespace std;

/*
Consider an array of integers, A = {a0, a1, ... an-1], where all but one of the integers occur in pairs.
In other words, every element in occurs exactly twice except for one unique element.

Given , find and print the unique element.
*/

int main(int argc, char *argv[])
{
    int n; cin >> n;

    if(n < 2)
    {
        cin >> n;
        cout << n;
        return;
    }

    int arr[n];
    for(int i = 0; i < n; ++i)
        cin >> arr[i];

    // if we xor a number with itself, result is 0.
    // if we have a list with pairs, result would be 0
    // if we have a different one, result would be this number.

    int result = arr[0] ^ arr[1];

    for(int i = 2; i < n; ++i){
        result ^= arr[i];
    }

    cout << result;
    return 0;
}
