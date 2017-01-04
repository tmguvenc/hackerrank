#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <map>

using namespace std;

inline bool is_left(const char& c){
    return c == '{' || c == '(' || c == '[';
}

char lookup[130];

bool balanced(const string& line){
    stack<char> bracket_stack;

    for(auto c : line){
        if(is_left(c))
            bracket_stack.push(c);
        else{
            if(bracket_stack.empty() || lookup[bracket_stack.top()] != c) return false;
            bracket_stack.pop();
        }
    }

    return bracket_stack.empty();
}

int main() {
    int count; cin >> count;

    lookup[123] = '}';
    lookup[40] = ')';
    lookup[91] = ']';

    for(int i = 0; i < count; ++i){
        string line; cin >> line;
        cout << (balanced(line) ? "YES" : "NO") << endl;
    }

    return 0;
}
