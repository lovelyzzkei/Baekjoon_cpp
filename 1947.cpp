#include <iostream>

#define INF 1000000000

using namespace std;

long long int dp[1000001];

int main(void)
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    dp[1] = 0;
    dp[2] = 1;
    for (int i = 3; i <= n; i++) {
        dp[i] = ((i-1)*((dp[i-1] + dp[i-2]) % INF)) % INF;
    }

    cout << dp[n];
    return 0;
}

