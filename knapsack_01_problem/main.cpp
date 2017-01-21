#include <iostream>

using namespace std;

/*
 * Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
 * In other words, given two integer arrays val[0..n-1] and wt[0..n-1] which represent values and weights associated with n items respectively.
 * Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this
 * subset is smaller than or equal to W. You cannot break an item, either pick the complete item, or don’t pick it (0-1 property).
 *
*/

long getMaxTotal(long values[], long weights[], int size, long W, int index){
    if(index == size || W == 0)
        return 0;

    // if the current weight is over our W, then skip this item.
    if(weights[index] > W)
        return getMaxTotal(values, weights, size, W, index + 1);

    else{

        // calculate total weight, if we include the current item
        long included = values[index] + getMaxTotal(values, weights, size, W - weights[index], index + 1);

        // calculate total weight, if we don't include the current item
        long not_included = getMaxTotal(values, weights, size, W, index + 1);

        // get the max of two weights
        return std::max(included, not_included);
    }
}

long getMaxTotal(long values[], long weights[], int size, long W){
    return getMaxTotal(values, weights, size, W, 0);
}

int main(int argc, char *argv[])
{
    long val[] = {1, 4, 5, 7};
    long wt[] = {1, 3, 4, 5};
    long W = 7;
    int size = sizeof(val) / sizeof(val[0]);

    cout << getMaxTotal(val, wt, size, W) << endl;

    return 0;
}
