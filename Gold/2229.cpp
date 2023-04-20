#include <iostream>

#define MAX 1001

using namespace std;

int main(void)
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int score[MAX], dp[MAX];
    for (int i = 0; i < n; i++) {
        cin >> score[i];
    }
    fill_n(dp, n, 0);

    int** group = new int*[MAX];
    for (int i = 0; i < n; i++) {
        group[i] = new int[MAX];
    }

    for (int i = 0; i < n; i++) {
        int maxNum = score[i];
        int minNum = score[i];
        group[i][i] = 0;
        for (int j = i; j < n; j++) {
            maxNum = max(maxNum, score[j]);
            minNum = min(minNum, score[j]);
            group[i][j] = maxNum - minNum;
        }
    }

    for (int i = 0; i < n; i++) {
        dp[i] = group[0][i];
        for (int j = 0; j < i; j++) {
            dp[i] = max(dp[i], dp[j] + group[j+1][i]);
        }
    }
    
    cout << dp[n-1];
    return 0;
}