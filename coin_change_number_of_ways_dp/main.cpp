#include <iostream>
#include <unordered_map>
#include <boost/timer.hpp>

using namespace std;

/*
 * Coin Changing Number of ways to get total using memoization
*/

long number_of_ways(long coins[], long coinCount, long money, long coinIndex, unordered_map<string, long>& map, long& cache_hit){

    // if we are out of money, then return 1 because we have 1 way to get 0. (empty set)
    if(money == 0)
        return 1;

    // if we used all the coin types, then we run out of options, return 0
    if(coinIndex == coinCount)
        return 0;

    // if we made this calculation before, then return it.
    string key = to_string(money) + "-" + to_string(coinIndex);
    auto w = map.find(key);
    if(w != map.end()){
        cache_hit++;
        return w->second;
    }

    long amount = 0;
    long ways = 0;
    while(amount <= money){
        long remaining = money - amount;
        ways += number_of_ways(coins, coinCount, remaining, coinIndex + 1, map, cache_hit);
        amount += coins[coinIndex];
    }
    map[key] = ways;
    return ways;
}

long number_of_ways(long coins[], long coinCount, long money){
    unordered_map<string, long> map;
    long cache_hit;
    auto ways = number_of_ways(coins, coinCount, money, 0, map, cache_hit);
    return ways;
}

int main(long argc, char *argv[])
{
    long coins[] = {1, 2, 3, 5, 6, 9, 11, 14, 20, 30, 32};
    long coinCount = sizeof(coins) / sizeof(coins[0]);

    boost::timer timer;

    cout << number_of_ways(coins, coinCount, 250) << endl;

    cout << timer.elapsed()*1000 << " ms." << endl;

    return 0;
}
