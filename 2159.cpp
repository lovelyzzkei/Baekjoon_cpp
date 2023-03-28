#include <iostream>
#include <climits>
#include <cmath>

#define MAX_N 100001

using namespace std;

int n;
long long int dp[MAX_N][5];
long long int restaurant[MAX_N][2];
int dx[] = {0, 1, 0, -1, 0};
int dy[] = {0, 0, 1, 0, -1};


bool inRange(int x, int y) 
{
    return (0 <= x && x <= MAX_N-1) && (0 <= y && y <= MAX_N-1);
}


int distance(int cx, int cy, int px, int py)
{
    return abs(px - cx) + abs(py - cy); 
}


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i <= n; i++) {
        cin >> restaurant[i][0] >> restaurant[i][1];
    }

    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        fill_n(dp[i], 5, LLONG_MAX);
        for (int dir = 0; dir < 5; dir++) {
            long long int cx = restaurant[i][0] + dx[dir];
            long long int cy = restaurant[i][1] + dy[dir];

            if (inRange(cx, cy)) 
            {
                for (int prev_dir = 0; prev_dir < 5; prev_dir++) {
                    long long int px = restaurant[i-1][0] + dx[prev_dir];
                    long long int py = restaurant[i-1][1] + dy[prev_dir];

                    if (i == 1)
                    {
                        px = restaurant[0][0];
                        py = restaurant[0][1];
                    }
                    if (inRange(px, py))
                    {
                        dp[i][dir] = min(dp[i][dir], dp[i-1][prev_dir] + distance(cx, cy, px, py));
                    }
                }
            }
        }
    }

    long long int ret = LLONG_MAX;
    for (int i = 0; i < 5; i++) {
        ret = min(ret, dp[n][i]);
    }

    cout << ret;

    return 0;
}