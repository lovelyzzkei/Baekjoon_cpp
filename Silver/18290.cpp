#include <iostream>
#include <memory.h>

#define N 11
#define M 11
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, k, grid[N][M];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
bool visited[N][M];

bool inRange(int y, int x)
{
    return (0 <= y && y < n) && (0 <= x && x < m);
}

bool near(int y, int x)
{
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (!inRange(ny, nx))
            continue;
        if (inRange(ny, nx) && visited[ny][nx])
            return true;
    }
    return false;
}

int select(int cnt)
{
    if (cnt == 0)
        return 0;   

    int ret = -1000000000;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && !near(i, j)) 
            {
                visited[i][j] = true;
                ret = max(ret, grid[i][j] + select(cnt-1));
                visited[i][j] = false;
            }
        }
    }

    return ret;
}


int main(void)
{
    FAST_IO;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            cin >> grid[i][j];
    
    memset(visited, 0, N*M*sizeof(bool));
    cout << select(k);
    return 0;
}