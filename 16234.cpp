#include <iostream>
#include <vector>
#include <deque>
#include <utility>
#include <memory.h>

#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MAX_N 51

using namespace std;

int n, l, r;
int states[MAX_N][MAX_N];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int visited[MAX_N][MAX_N];
int unions[MAX_N*MAX_N];

bool inRange(int y, int x)
{
    return (0 < y && y <= n) && (0 < x && x <= n);
}


bool openBorder(int y1, int x1, int y2, int x2)
{
    int diff = abs(states[y1][x1] - states[y2][x2]);
    return (l <= diff && diff <= r);
}


int findUnion(int y, int x, int idx)
{
    int num = 1, sum = 0;

    deque<pair<int, int>> dq;
    visited[y][x] = idx;
    dq.push_back(make_pair(y, x));

    while (!dq.empty()) {
        pair<int, int> curr = dq.front();
        int cy = curr.first;
        int cx = curr.second;
        sum += states[cy][cx];


        dq.pop_front();

        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if (inRange(ny, nx) && !visited[ny][nx] && openBorder(cy, cx, ny, nx))
            {
                num++;
                visited[ny][nx] = idx;
                dq.push_back(make_pair(ny, nx));
            }
        }
    }

    if (num != 1)
        unions[idx] = (sum / num);

    return num;
}

int main(void)
{
    FAST_IO;
    
    cin >> n >> l >> r;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> states[i][j];
        }
    } 
    
    int day = 0;
    while (true) {
        int numUnion = 0, unionIdx = 1;
        memset(visited, 0, MAX_N*MAX_N*sizeof(int));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (!visited[i][j]) 
                {
                    int cnt = findUnion(i, j, unionIdx);
                    if (cnt > 1)
                    {
                        numUnion++;
                        unionIdx++;
                    }
                    else
                        visited[i][j] = 0;
                }
            }
        }

        if (numUnion == 0)
            break;

        

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (visited[i][j])
                {
                    states[i][j] = unions[visited[i][j]];
                }
            }
        }

        day++;
    }

    cout << day;
    return 0;

}
