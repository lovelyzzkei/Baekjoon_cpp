#include <iostream>
#include <string>
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int main(void)
{
    FAST_IO;
    string c;
    int a = 0, b = 0;
    for (int i = 0; i < 6; i++) {
        cin >> c;
        if (c == "W") a++;
        else b++;
    }

    if (a >= 5) cout << 1;
    else if (a >= 3) cout << 2;
    else if (a >= 1) cout << 3;
    else cout << -1;

    return 0;
}