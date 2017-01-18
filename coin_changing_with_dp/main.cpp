#include <iostream>
#include <iomanip>
#include <stack>

using namespace std;

/*
 * Given set of coins of unlimited quantity and a total. How many minimum coins would it take to form this total.
*/

int main(int argc, char *argv[])
{
    int coins[] = {1, 2, 5, 10, 25};
    //int coins[] = {1, 5, 6, 8};
    int coinCount = sizeof(coins) / sizeof(coins[0]);
    int change = 74;

    int matrix[coinCount][change + 1];

    for(int i = 0; i < coinCount; ++i){
        for(int j = 0; j < change + 1; ++j)
            matrix[i][j] = 0;
    }

    for(int i = 0; i < coinCount; ++i){
        for(int j = 1; j <= change; ++j){
            if(coins[i] <= j){
                if(i > 0)
                    matrix[i][j] = min(matrix[i - 1][j], 1 + matrix[i][j - coins[i]]);
                else
                    matrix[i][j] = 1 + matrix[i][j - coins[i]];
            }else{
                matrix[i][j] = matrix[i - 1][j];
            }
        }
    }

    stack<int> usedCoins;

    int a = coinCount - 1;
    int b = change;

    while(b){

        if(matrix[a][b] == matrix[a - 1][b]){
            --a;
        }
        else{
            usedCoins.push(coins[a]);
            b -= coins[a];
        }
    }

    cout << "Solution: { ";

    while(!usedCoins.empty()){
        cout << usedCoins.top() << " ";
        usedCoins.pop();
    }

    cout << "}" << endl;
    return 0;
}
