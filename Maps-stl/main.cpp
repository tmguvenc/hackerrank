#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int query_count; cin >> query_count;

    map<string, int> mymap;

    for(int i = 0; i < query_count; ++i){
        int command, grade;
        string name;
        cin >> command;
        if(command == 1){
            cin >> name >> grade;
            auto aa = mymap.find(name);
            if(aa != mymap.end()){
                aa->second += grade;
            }
            else{
                mymap.insert(make_pair(name, grade));
            }
        }
        else if(command == 2){
            cin >> name;

            auto aa = mymap.find(name);
            if(aa != mymap.end()){
                mymap.erase(name);
            }
        }
        else if(command == 3){
            cin >> name;

            auto aa = mymap.find(name);
            if(aa != mymap.end()){
                cout << aa->second << endl;
            }
            else{
                cout << "0" << endl;
            }
        }
    }

    return 0;
}
