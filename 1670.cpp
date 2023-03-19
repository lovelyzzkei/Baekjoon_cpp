#include <iostream>

#define MAX 10001
#define INF 987654321

using namespace std;

int n;
long long int dp[MAX];

long long int shakeHand(int num)
{
    long long int& cache = dp[num];
    if (num == 0 || num == 2) return 1;
    if (cache != -1) return cache;

    cache = 0;
    for (int i = 2; i <= num; i+=2) {
        cache += shakeHand(i-2) * shakeHand(num-i);
        cache %= INF;
    }

    return cache % INF;
}



int main(void)
{
    cin >> n;
    fill_n(dp, n+1, -1);

    dp[0] = 1;
    dp[2] = 1;
    dp[4] = 2;

    cout << shakeHand(n) << endl;
    // for (int i = 0; i <= n; i+=2) 
    // {
    //     cout << dp[i] << " ";
    // }
    // cout << endl;

    cout << dp[n];
    return 0;
}
