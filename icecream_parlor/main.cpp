#include <iostream>
#include <boost/random.hpp>
#include <unordered_map>

using namespace  std;

/*
    put the total's complement (which means: total - item) into hash map and
    search this item in the rest of the array
    O(N) complexity
*/
std::pair<int, int> find_index(int arr[], int size, int total){
    unordered_map<int, int> map;
    for(int i = 0; i < size; ++i){
        auto elem = map.find(arr[i]);
        if(elem == map.end())
            map.insert(make_pair(total - arr[i], i));
        else
            return make_pair(elem->second, i);
    }
    return make_pair(-1, -1);
}

int main(int argc, char *argv[])
{
    const int LEN = 200;
    boost::random::mt19937 rng;
    boost::random::uniform_int_distribution<> aa(0, LEN);

    int arr[LEN];
    cout << "[ ";
    for(int i = 0; i < LEN; ++i){
        arr[i] = aa(rng);
        cout << arr[i] << " ";
    }
    cout << "]" << endl;

    auto indexes = find_index(arr, sizeof(arr) / sizeof(int), 250);

    if(indexes.first != -1 && indexes.second != -1){
        cout << "[" << indexes.first << ", " << indexes.second << "]" << endl;
    }else{
        cout << "Not Found!" << endl;
    }

    return 0;
}
