#include <iostream>
#include <deque>
#include <utility>

#define N 501
#define M 501
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, paper[N][M];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
bool visited[N][M];

bool inRange(int y, int x)
{
    return (0 <= y && y < n) && (0 <= x && x < m);
}

int bfs(int y, int x)
{
    deque<pair<int, int>> dq;
    dq.emplace_back(y, x);
    visited[y][x] = true;

    int ret = 0;
    while (!dq.empty()) {
        pair<int, int> curr = dq.front();
        int cy = curr.first;
        int cx = curr.second;
        dq.pop_front();
        ret++;

        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if (inRange(ny, nx) && !visited[ny][nx] && paper[ny][nx] == 1)
            {
                visited[ny][nx] = true;
                dq.emplace_back(ny, nx);
            }
        }
    }

    return ret;
}

int main(void)
{
    FAST_IO;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> paper[i][j];
        }
    }

    int area = 0, num = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && paper[i][j] == 1)
            {
                area = max(area, bfs(i, j));
                num++;
            }
        }
    }

    cout << num << endl;
    cout << area;
    return 0;
}