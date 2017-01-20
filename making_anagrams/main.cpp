#include <iostream>
#include <unordered_map>

using namespace std;

// number of characters in english alphabet
const int CHAR_COUNT = 26;

int number_needed(string a, string b) {

    char chars[CHAR_COUNT + 1] = {0};

    for(const auto& c : a)
        chars[c - 'a']++;
    for(const auto& c : b)
        chars[c - 'a']--;

    int diff = 0;
    for(int i = 0; i <= CHAR_COUNT; ++i){
        diff += std::abs(chars[i]);
    }

    return diff;
}

int main(){
    string a;
    cin >> a;
    string b;
    cin >> b;
    cout << number_needed(a, b) << endl;
    return 0;
}
