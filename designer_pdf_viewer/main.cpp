#include <iostream>
#include <map>

using namespace std;

int main(int argc, char *argv[])
{
    map<char, int> height_map;
    int h;
    for(int i = 0; i < 26; ++i){
        cin >> h;
        height_map.insert(make_pair('a' + i, h));
    }

    string str; cin >>str;

    int area = 1 * str.length();
    int max_h = 1;
    for(const auto& c : str){
        auto h = height_map[c];
        if(h > max_h)
            max_h = h;
    }

    cout << area * max_h;
    return 0;
}
