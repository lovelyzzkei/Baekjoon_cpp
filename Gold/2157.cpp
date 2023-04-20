#include <iostream>
#include <cmath>

#define MAX_N 301
#define INF 1000000007

using namespace std;

int main(void)
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, k;
    int food[MAX_N][MAX_N], dp[MAX_N][MAX_N];
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            food[i][j] = -1;
        }
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            dp[i][j] = -1;
        }
    }
    dp[1][1] = 0;

    int a, b, c;
    for (int i = 0; i < k; i++) {
        cin >> a >> b >> c;
        food[a][b] = max(food[a][b], c);
    }

    for (int i = 2; i <= n; i++) {
        for (int k = 1; k < i; k++) {
            for (int j = 2; j <= m; j++) {
                if (food[k][i] != -1 && dp[k][j-1] != -1) 
                {
                    dp[i][j] = max(dp[i][j], food[k][i] + dp[k][j-1]);
                }
            }
        }
    }


    int ret = 0;
    for (int i = 1; i <= m; i++) {
        ret = max(ret, dp[n][i]);
    }
    cout << ret;

    return 0;
}