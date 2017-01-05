#include <iostream>
#include <assert.h>
#include <map>
using namespace std;

char find_first_non_repeated(const string& str){
    map<char, int> m;
    for(const auto& c : str){
        auto aa = m.find(c);
        if(aa == m.end())
            m.insert(make_pair(c, 1));
        else
            aa->second++;
    }
    for(const auto& c : str)
        if(m[c] == 1)
            return c;
}

int main(int argc, char *argv[])
{
    char c = find_first_non_repeated("LoveYourself");
    char test = 'v';
    assert(c == test);
    return 0;
}
