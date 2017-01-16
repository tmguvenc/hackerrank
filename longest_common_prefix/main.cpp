#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string getCommonString(const string& s1, const string& s2){

    int size = s1.size() > s2.size() ? s1.size() : s2.size();

    stringstream ss;

    for(int i = 0; i < size; ++i){
        if(s1[i] == s2[i])
            ss << s1[i];
        else
            break;
    }

    return ss.str();
}

string longest_common_prefix(string arr[], int left, int right){
    if(left == right)
        return arr[left];
    int middle = left + (right - left) / 2;
    auto l = longest_common_prefix(arr, left, middle);
    auto r = longest_common_prefix(arr, middle + 1, right);
    return getCommonString(l, r);
}

string longest_common_prefix(string arr[], int size){
    return longest_common_prefix(arr, 0, size - 1);
}

int main(int argc, char *argv[])
{
    string arr[] = {"geeksforgeeks", "geeks", "geek", "geezer"};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << longest_common_prefix(arr, size) << endl;

    return 0;
}
