#include <iostream>
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int main(void)
{
    FAST_IO;
    int n, t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        int sum = 0;
        for (int j = 1; j <= n; j+=2)
            sum += j;
        cout << sum << endl;
    }
    return 0;
}