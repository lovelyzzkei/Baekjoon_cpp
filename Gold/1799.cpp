#include <iostream>
#include <string>
#include <memory.h>

#define N 11
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int n, chess[N][N], wb[N][N], bans = 0, wans = 0;
bool visited[N][N], diag_l[2*N-1], diag_r[2*N-1];

void dfs(int r, int c, int color)
{
    if (r == n)
    {        
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j])
                    cnt++;
            }
        }

        if (color == 0) bans = max(bans, cnt);
        else wans = max(wans, cnt);
        return;
    }

    if (c == n)
    {
        dfs(r+1, 0, color);
        return;
    }

    // place where bishop cannot be located
    if (wb[r][c] != color || !chess[r][c] || diag_l[r-c+n-1] || diag_r[r+c])
    {
        dfs(r, c+1, color);
        return;
    }
    
    diag_l[r-c+n-1] = true;
    diag_r[r+c] = true;
    visited[r][c] = true;
    dfs(r, c+1, color);

    diag_l[r-c+n-1] = false;
    diag_r[r+c] = false;
    visited[r][c] = false;
    dfs(r, c+1, color);
}


int main(void)
{
    FAST_IO;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> chess[i][j];
            if ((i+j) % 2 == 0) wb[i][j] = 0;
            else wb[i][j] = 1;
        }
    }

    memset(visited, 0, N*N*sizeof(bool));
    dfs(0, 0, 0);
    dfs(0, 0, 1);

    cout << bans + wans;
    return 0;
}