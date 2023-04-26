#include <iostream>
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main(void)
{
    FAST_IO;
    int n;
    cin >> n;

    long long int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += (n / i)*i;
    }
    cout << sum;
    return 0;
}