#include <iostream>

#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int main(void)
{
    FAST_IO;
    int a, b;
    while (true) {
        cin >> a >> b;
        if (a == 0 && b == 0)
            break;

        cout << ((a > b) ? "Yes" : "No") << endl; 
    }
    return 0;
}