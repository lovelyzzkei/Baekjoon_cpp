#include <iostream>

#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int main(void)
{
    FAST_IO;
    int t, n, num = 0;
    cin >> t;
    for (int i = 0; i < 5; i++) {
        cin >> n;
        if (t == n)
            num++;
    }
    cout << num;
    return 0;
}