#include <iostream>
#include <unordered_map>
#include <limits>

using namespace std;

/*
 * Coin Changing: minimum number of coins to get total using memoization
*/

long find_min_coin_count(long coins[], long coinCount, long money, unordered_map<long, long>& cache){

    if(money == 0)
        return 0;

    auto found = cache.find(money);
    if(found != cache.end())
        return found->second;

    auto minValue = std::numeric_limits<long>::max();

    for(int i = 0; i < coinCount; ++i){
        if(coins[i] > money)
            continue;

        auto remaining = money - coins[i];
        auto minimum = find_min_coin_count(coins, coinCount, remaining, cache);

        if(minimum < minValue)
            minValue = minimum;
    }

    minValue = (minValue == std::numeric_limits<long>::max() ? minValue : minValue + 1);

    cache[money] = minValue;

    return minValue;
}

long find_min_coin_count(long coins[], long coinCount, long money){
    unordered_map<long, long> cache;
    return find_min_coin_count(coins, coinCount, money, cache);
}

int main(int argc, char *argv[])
{
    long coins[] = {1,2,3, 5, 6, 10, 50, 100, 200};
    long coinCount = sizeof(coins) / sizeof(coins[0]);

    cout << find_min_coin_count(coins, coinCount, 12345) << endl;

    return 0;
}
