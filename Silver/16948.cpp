#include <iostream>
#include <deque>
#include <utility>
#include <memory.h>

#define N 201
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int n, r1, c1, r2, c2;
int dy[] = {-2, -2, 0, 0, 2, 2};
int dx[] = {-1, 1, -2, 2, -1, 1};
bool visited[N][N];

bool inRange(int y, int x)
{
    return (0 <= y && y < n) && (0 <= x && x < n);
}

int main(void)
{
    FAST_IO;
    cin >> n;
    cin >> r1 >> c1 >> r2 >> c2;
    
    deque<pair<int, int>> dq;
    dq.emplace_back(r1, c1);
    visited[r1][c1] = true;

    int move = 0;
    bool isArrived = false;

    while (!dq.empty()) {
        int size = dq.size();
        for (int _ = 0; _ < size; _++) {
            pair<int, int> curr = dq.front();
            int y = curr.first;
            int x = curr.second;
            dq.pop_front();

            if (y == r2 && x == c2)
            {
                isArrived = true;
                break;
            }

            for (int i = 0; i < 6; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if (inRange(ny, nx) && !visited[ny][nx])
                {
                    visited[ny][nx] = true;
                    dq.emplace_back(ny, nx);
                }
            }
        }

        if (isArrived)
            break;

        move++;
    }

    if (isArrived)
        cout << move;
    else
        cout << -1;

    return 0;
}