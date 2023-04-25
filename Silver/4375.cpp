#include <iostream>
#include <string>
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int n;

int main(void)
{
    FAST_IO;
    while (cin >> n)
    {
        int tmp = 0;
        for (int i = 1; i <= n; i++) {
            tmp = tmp * 10 + 1;
            tmp %= n;
            if (tmp == 0)
            {
                cout << i << endl;
                break;
            }
        }
    }

    return 0;
}