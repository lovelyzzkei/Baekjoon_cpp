#include <iostream>
#include <string>
#include <memory.h>

#define N 4
#define M 4
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, arr[N][M], ans;
bool visited[N][M];

void dfs(int r, int c)
{
    if (r == n)
    {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int tmp = 0;
            for (int j = 0; j < m; j++) {
                if (visited[i][j]) 
                    tmp = tmp*10 + arr[i][j];
                else
                {
                    sum += tmp;
                    tmp = 0;
                }
            }
            sum += tmp;
        }

        for (int i = 0; i < m; i++) {
            int tmp = 0;
            for (int j = 0; j < n; j++) {
                if (!visited[j][i])
                    tmp = tmp*10 + arr[j][i];
                else
                {
                    sum += tmp;
                    tmp = 0;
                }
            }
            sum += tmp;
        }

        ans = max(ans, sum);
        return;
    }

    if (c == m)
    {
        dfs(r+1, 0);
        return;
    }

    visited[r][c] = true;
    dfs(r, c+1);

    visited[r][c] = false;
    dfs(r, c+1);

    return;
}

int main(void)
{
    FAST_IO;
    cin >> n >> m;

    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++) {
            arr[i][j] = s[j] - '0';
        }
    }

    memset(visited, 0, N*M*sizeof(bool));
    dfs(0, 0);

    cout << ans;
    return 0;
}