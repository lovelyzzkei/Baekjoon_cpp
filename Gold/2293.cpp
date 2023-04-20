#include <iostream>

#define MAX_N 101
#define MAX_K 10001

using namespace std;

int main(void)
{
    int n, k;
    int coins[MAX_N], dp[MAX_K];
    
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    for (int i = 0; i <= k; i++) {
        dp[i] = 0;
    }

    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = coins[i]; j <= k; j++) {
            if (j - coins[i] >= 0) {
                dp[j] += dp[j-coins[i]];
            }
        }
    }

    cout << dp[k];
    return 0;
}