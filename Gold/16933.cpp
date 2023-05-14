#include <iostream>
#include <deque>
#include <string>
#include <memory.h>

#define N 1001
#define M 1001
#define K 11
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, k, arr[N][M];
int dy[] = {-1, 0, 1, 0, 0};
int dx[] = {0, 1, 0, -1, 0};
bool visited[N][M][K][2];

struct Person {
    int y;
    int x;
    int wall;
    Person(int _y, int _x, int _w) : y(_y), x(_x), wall(_w) {}
};

bool inRange(int y, int x) 
{
    return (0 <= y && y < n) && (0 <= x && x < m);
}

int main(void)
{
    FAST_IO;
    cin >> n >> m >> k;

    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++) {
            arr[i][j] = s[j] - '0';
        }
    }

    bool isArrived = false;
    memset(visited, 0, N*M*K*2*sizeof(bool));
    int day = 0, dist = 1;

    deque<Person> dq;
    dq.emplace_back(0, 0, 0);
    visited[0][0][0][day] = true;

    while (!dq.empty()) {
        int size = dq.size();
        for (int _ = 0; _ < size; _++) {
            Person curr = dq.front();
            int y = curr.y;
            int x = curr.x;
            int wall = curr.wall;
            dq.pop_front();

            // cout << y << " " << x << " " << wall << endl;

            if (y == n-1 && x == m-1)
            {
                isArrived = true;
                break;
            }

            for (int i = 0; i < 5; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if (inRange(ny, nx))
                {
                    if (arr[ny][nx] == 1)
                    {
                        if (day == 0 && wall < k && !visited[ny][nx][wall+1][day])
                        {
                            visited[ny][nx][wall+1][day] = true;
                            dq.emplace_back(ny, nx, wall+1);
                        }
                        else if (day == 1 && ny == y && nx == x && !visited[ny][nx][wall][day])
                        {
                            visited[ny][nx][wall][day] = true;
                            dq.emplace_back(ny, nx, wall);
                        }
                    }
                    if (arr[ny][nx] == 0 && !visited[ny][nx][wall][day])
                    {
                        visited[ny][nx][wall][day] = true;
                        dq.emplace_back(ny, nx, wall);
                    }
                }
            }
        }
        // cout << endl;

        if (isArrived)
            break;

        dist++;
        day = day ^ 1;
    }

    if (isArrived)
        cout << dist;
    else
        cout << -1;
    
    return 0;
}