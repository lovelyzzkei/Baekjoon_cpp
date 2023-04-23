#include <iostream>

#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int main(void)
{
    FAST_IO;
    long long int a, b;
    cin >> a >> b;
    if (a == b) {
        cout << 0 << endl;
        return 0;
    }
    cout << abs(b - a) - 1 << endl;
    for (long long int i = min(a, b) + 1; i < max(a, b); i++) {
        cout << i << " ";
    }
    return 0;
}