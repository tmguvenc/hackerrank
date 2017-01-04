#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <cstring>

using namespace std;

struct Command{
    int command;
    string str;
    Command(int c, const string& s) : command(c), str(move(s)) { }

    Command& operator=(Command&& other){
        this->str = move(other.str);
        this->command = other.command;
        return *this;
    }

    Command(Command &&other){
        this->command = other.command;
        this->str = move(other.str);
    }

private:
    Command& operator=(const Command& other);
    Command(const Command& other);
};

int main() {

    int Q; cin >> Q;

    stack<Command> st;

    char S[1000000] = {0};

    int index = 0;

    for(int i = 0; i < Q; ++i){

        int command; cin >> command;

        if(command == 1){
            string str; cin >> str;
            strcpy(S + index, str.c_str());
            index += str.length();
            st.push(Command(command, str));
        }
        else if(command == 2){
            int count; cin >> count;
            char cropped[count + 1] = {0};
            index -= count;
            strncpy(cropped, S + index, count);
            st.push(Command(command, string(cropped)));
        }
        else if(command == 3){
            int count; cin >> count;
            cout << S[count - 1] << endl;
        }
        else if(command == 4){
            const auto &cmd = st.top();
            // if the command was append, then remove the last added string from S
            if(cmd.command == 1){
                index -= cmd.str.length();
            }
            else{
                strcpy(S + index, cmd.str.c_str());
                index += cmd.str.length();
            }
            st.pop();
        }
    }

    return 0;
}
