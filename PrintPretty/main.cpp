#include <iostream>
#include <iomanip>
#include <cmath>
#include <sstream>
#include <locale>

using namespace std;

int main() {
    int T; cin >> T;
    cout << setiosflags(ios::uppercase);
    cout << setw(0xf) << internal;
    while(T--) {
        double A; cin >> A;
        double B; cin >> B;
        double C; cin >> C;

        auto old_flags = cout.flags();
        cout << left << hex << showbase << nouppercase << (long long)A << endl;
        //cout.flags(old_flags);
        cout << setw(0xf) << internal << right << setfill('_') << setiosflags(ios::fixed) << showpos << setprecision(2) << B << endl;
        cout.flags(old_flags);
        cout << setiosflags(ios::uppercase | ios::scientific) << dec << noshowpos << setprecision(9) << C << endl;
    }
    return 0;
}
