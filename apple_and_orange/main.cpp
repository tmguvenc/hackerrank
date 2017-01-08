#include <iostream>
#include <assert.h>

using namespace std;

int main(int argc, char *argv[])
{
    int s, t, a, b, m, n;
    cin >> s >> t >> a >> b >> m >> n;

    const auto size = b - a + 1;
    bool arr[size] = {0};
    for(int i = s - a; i <= t - a; ++i)
        arr[i] = true;

    int apple = 0;
    int orange = 0;

    for(int i = 0; i < m; ++i){
        int temp; cin >> temp;
        if(temp < 0) continue;
        if(temp < size && arr[temp]) apple++;
    }

    cout << apple << endl;

    for(int i = 0; i < n; ++i){
        int temp; cin >> temp;
        if(temp > 0) continue;
        auto ind = size + temp - 1;
        if(ind >= 0 && arr[ind]) orange++;
    }

    cout << apple << endl;

    return 0;
}
