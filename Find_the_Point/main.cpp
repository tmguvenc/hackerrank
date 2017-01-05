#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int count; cin >> count;
    for(int i = 0; i < count; ++i){
        int px, py, qx, qy;
        cin >> px >> py >> qx >> qy;
        cout << px + 2 * (qx-px) << " " << py + 2*(qy-py) << endl;
    }
    return 0;
}
