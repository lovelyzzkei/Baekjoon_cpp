#include <iostream>
#include <cmath>
#include <climits>
#include <vector>
#include <algorithm>

#define MAX 1001

using namespace std;

int n, m;
vector<int> dp(MAX, INT_MAX);
vector<int> name(MAX, 0);

int deathNote(int start)
{
    int& cache = dp[start];
    if (cache < INT_MAX) return cache;

    int remain = m - name[start];

    for (int i = start+1; i <= n && remain >= 0; i++) {
        if (i == n)
        {
            cache = 0;
            break;
        }
        cache = min(cache, remain*remain + deathNote(i));
        remain -= (name[i] + 1);
    }
    return cache;
}


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> name[i];
    }

    dp[n-1] = 0;

    cout << deathNote(0);
    return 0;
}