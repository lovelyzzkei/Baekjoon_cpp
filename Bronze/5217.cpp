#include <iostream>
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int main(void)
{
    FAST_IO;
    int t, n;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        cout << "Pairs for " << n << ": ";

        for (int i = 1; i <= n / 2; i++) {
            if (i != n-i)
            {
                if (i > 1)
                    cout << ", ";
                cout << i << " " << n - i;
            }
        }
        cout << endl;
    }
    return 0;
}