#include <iostream>
#include <vector>

using namespace std;

int binary_search(const std::vector<int> &v, int elem, int left, int right){
    if(left > right)
        return -1;
    int middle = left + (right - left) / 2;
    if(elem == v[middle])
        return middle;
    else if(elem < v[middle])
        return binary_search(v, elem, left, middle - 1);
    else
        return binary_search(v, elem, middle + 1, right);
}

int binary_search(const std::vector<int>& v, int elem){
    return binary_search(v, elem, 0, v.size() - 1);
}

int main(int argc, char *argv[])
{
    cout << "index: " << binary_search({1,21,32,44,55,66,78,89,90}, 12) << endl;
    return 0;
}
