#include <iostream>
#include <cmath>

#define MAX 1000001
#define INF 1000000000

using namespace std;

double logB(int x, int base) {
    return log(x)/log(base);
}

int main(void)
{
    int n;
    cin >> n;

    int power_two[20];
    int num = (int)logB(n, 2);

    for (int i = 0; i <= (int)logB(n, 2); i++) {
        power_two[i] = pow(2, i);
    }

    int* dp;
    dp = new int[MAX];
    for (int i = 0; i <= n; i++) {
        dp[i] = 0;
    }
    dp[0] = 1;

    for (int i = 0; i <= num; i++) {
        for (int j = power_two[i]; j <= n; j++) {
            if (j - i >= 0) {
                dp[j] = (dp[j] + dp[j-power_two[i]]) % INF;
            }
        }
    }

    cout << dp[n];
    return 0;
}