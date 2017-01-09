#include <iostream>
#include <unordered_map>
#include <iomanip>
#include <assert.h>

using namespace std;

double long fib(int num){
    if(num < 3) return 1;
    static std::unordered_map<int, double long> map;
    auto aa = map.find(num);
    if(aa != map.end())
        return aa->second;
    double long value = fib(num - 1) + fib(num - 2);
    map.insert(make_pair(num, value));
    return value;
}

int main(int argc, char *argv[])
{
    auto aa = 18547707689471986212190138521399707760;
    auto bb = fib(180);
    assert(aa = bb);
    cout << fixed << bb << endl;
    return 0;
}
