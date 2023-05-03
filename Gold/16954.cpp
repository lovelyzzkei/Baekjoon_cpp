#include <iostream>
#include <deque>
#include <utility>
#include <memory.h>

#define N 8
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int chess[N][N];
int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1, 0};
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1, 0};
bool isArrived = false;
deque<pair<int, int>> dq;

bool inRange(int y, int x)
{
    return (0 <= y && y < N) && (0 <= x && x < N);
}

int main(void)
{
    FAST_IO;

    char c;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> c;
            if (c == '.')
                chess[i][j] = 0;
            else 
                chess[i][j] = 1;
        }
    }

    dq.push_back(make_pair(N-1, 0));
    while (!dq.empty()) {
        int size = dq.size();
        for (int _ = 0; _ < size; _++) {
            pair<int, int> curr = dq.front();
            int y = curr.first;
            int x = curr.second;
            dq.pop_front();

            if (chess[y][x])
                continue;
            
            if (y == 0 && x == N-1)
            {
                isArrived = true;
                break;
            }

            for (int i = 0; i < 9; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if (inRange(ny, nx) && !chess[ny][nx])
                {
                    dq.push_back(make_pair(ny, nx));
                }
            }
        }

        for (int i = N-1; i >= 0; i--) {
            for (int j = 0; j < N; j++) {
                if (chess[i][j] && inRange(i+1, j))
                {
                    chess[i+1][j] = 1;
                    chess[i][j] = 0;
                }
            }
        }
        
        if (isArrived)
            break;
    }

    if (isArrived)
        cout << 1;
    else
        cout << 0;

    return 0;
}