#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool findDuplicateParanthesis(const string& str){
    stack<char> st;

    for(const auto& c : str){
        if(c == ')'){
            if(!st.empty()){

                auto top = st.top();
                st.pop();

                if(top == '(')
                    return true;
                else{
                    while(top != '('){
                        top = st.top();
                        st.pop();
                    }
                }
            }else{
                return false;
            }
        }
        else{
            st.push(c);
        }
    }

    return false;
}

int main(int argc, char *argv[])
{
    cout << findDuplicateParanthesis("(((a+(b))+(c+d)))") << endl;
    return 0;
}
