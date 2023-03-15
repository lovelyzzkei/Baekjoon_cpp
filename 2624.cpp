#include <iostream>
#include <utility>
#include <vector>

using namespace std;

void initArray(int *arr, int len)
{
    for (int i = 0; i < len; i++) {
        arr[i] = 0;
    }
}

int main()
{
    int dp[10001];
    initArray(dp, sizeof(dp) / sizeof(int));

    int cashPrice, numOfCoins;
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> cashPrice >> numOfCoins;

    vector<pair<int, int>> coins(numOfCoins);

    for (int i = 0; i < numOfCoins; ++i) {
        int x, c;
        cin >> x >> c;
        coins[i] = {x, c};
    }

    dp[0] = 1;
    for (int i = 0; i < numOfCoins; ++i) {
        int coin_val = coins[i].first;
        int coin_cnt = coins[i].second;

        for (int j = cashPrice; j >= 0; --j) {
            for (int k = 1; k <= coin_cnt && j - k*coin_val >= 0; ++k) {
                dp[j] += dp[j-k*coin_val];
            }
        }
    }

    cout << dp[cashPrice];

    return 0;
}