#include <iostream>
#include <vector>

using namespace std;
using size_type = vector<int>::size_type;

/*
 * size1 = v1.size()
 * size2 = v2.size()
 * Complexity: O(size1 + size2)
 * linear time
*/
vector<int> findIntersection(const vector<int>& v1, const vector<int>& v2){
    vector<int> result;
    size_type i = 0;
    size_type j = 0;
    while(i < v1.size() && j < v2.size()){
        if(v1[i] == v2[j]) {
            result.push_back(v1[i++]);
            j++;
        }
        else if(v1[i] < v2[j]) i++;
        else j++;
    }

    return result;
}

/*
 * size1 = v1.size()
 * size2 = v2.size()
 * Complexity: O(size1 + size2)
 * linear time
*/
vector<int> findUnion(const vector<int>& v1, const vector<int>& v2){
    vector<int> result;
    size_type i = 0;
    size_type j = 0;
    while(i < v1.size() && j < v2.size()){
        if(v1[i] == v2[j]) {
            result.push_back(v1[i++]);
            j++;
        }
        else if(v1[i] < v2[j]) {
            result.push_back(v1[i++]);
        }
        else {
            result.push_back(v2[j++]);
        }
    }

    return result;
}

int main(int argc, char *argv[])
{
    for(const auto& a : findIntersection({1, 3, 4, 5, 7, 8, 11}, {2, 3, 5, 6, 11}))
        cout << a << " ";

    cout << endl;

    for(const auto& a : findUnion({1, 3, 4, 5, 7, 8, 11}, {2, 3, 5, 6, 11}))
        cout << a << " ";

    cout << endl;

    return 0;
}
