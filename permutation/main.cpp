#include <iostream>
#include <vector>
using namespace std;

void permutate(string str, string& output, bool used[]){
    if(output.size() == str.size()){
        cout << output << endl;
        return;
    }

    for(int i = 0; i < str.size(); ++i){
        if(used[i]) continue;
        output.push_back(str[i]);
        used[i] = true;
        permutate(str, output, used);
        used[i] = false;

    }
}

int main(int argc, char *argv[])
{
    string aa = "murat";
    bool used[aa.length()];

    for(int i = 0; i < aa.size(); ++i)
        used[i] = false;

    string output;

    permutate("murat", output, used);
    return 0;
}
