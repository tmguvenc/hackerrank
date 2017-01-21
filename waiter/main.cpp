#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

inline bool isPrime(int number){
    if(number < 2) return false;
    if(number == 2) return true;
    if(number % 2 == 0) return false;
    auto sq = sqrt(number);
    for(int i = 3; i <= sq; i += 2)
        if(number % i == 0) return false;
    return true;
}

vector<int> find_ith_prime(int number){
    int n = 2;
    int index = 0;
    vector<int> map(number + 1, 0);
    while(true){
        if(isPrime(n)){
            map[index] = n;
            if(index++ == number)
                break;
        }
        n++;
    }
    return map;
}

int main() {

    int N, Q;
    cin >> N >> Q;

    std::vector<int> prime_map = find_ith_prime(Q);

    std::stack<int> A;
    for(int i = 0; i < N; ++i){
        int temp;
        cin >> temp;
        A.push(temp);
    }

    std::queue<std::stack<int>> queueOfBStacks;
    std::queue<int> tempQueue;

    for(int i = 1; i <= Q; ++i){
        std::stack<int> bStack;
        while(!A.empty()){
            auto plateNumber = A.top();
            if(plateNumber % prime_map[i - 1] == 0){
                bStack.push(plateNumber);
            }else{
                tempQueue.push(plateNumber);
            }
            A.pop();
        }
        queueOfBStacks.push(bStack);
        while(!tempQueue.empty()){
            A.push(tempQueue.front());
            tempQueue.pop();
        }
    }

    while(!queueOfBStacks.empty()){
        std::stack<int>& bStack = queueOfBStacks.front();

        while(!bStack.empty()){
            cout << bStack.top() << endl;
            bStack.pop();
        }

        queueOfBStacks.pop();
    }

    while(!A.empty()){
        cout << A.top() << endl;
        A.pop();
    }

    return 0;
}
