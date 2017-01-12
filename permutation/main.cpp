#include <iostream>
#include <vector>
using namespace std;

void permutate(string source, vector<string>& dest, int start, int end){
    if(start == end){
        dest.push_back(source);
        return;
    }

    for(int i = start; i<=end; ++i){
        swap(source[start], source[i]);
        permutate(source, dest, start + 1, end);
        swap(source[start], source[i]);
    }
}

vector<string> permutate(string source){
    vector<string> permutations;
    permutate(source, permutations, 0, source.size() - 1);
    return permutations;
}

int main(int argc, char *argv[])
{
    string m("murat");
    for(auto& p : permutate(m))
        cout << p << endl;
    return 0;
}
