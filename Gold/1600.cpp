#include <iostream>
#include <deque>
#include <memory.h>

#define W 201
#define H 201
#define K 31
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int w, h, k, world[H][W];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int hdy[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int hdx[] = {1, 2, 2, 1, -1, -2, -2, -1};

bool visited[H][W][K];

struct Monkey {
    int y;
    int x;
    int horse;
    Monkey(int yy, int xx, int h) : y(yy), x(xx), horse(h) {}
};


bool inRange(int y, int x)
{
    return (0 <= y && y < h) && (0 <= x && x < w);
}

int main(void)
{
    FAST_IO;
    cin >> k >> w >> h;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> world[i][j];
        }
    }

    deque<Monkey> dq;
    dq.emplace_back(0, 0, 0);
    visited[0][0][0] = true;

    int move = 0;
    bool isArrived = false;

    while (!dq.empty()) {
        int size = dq.size();
        for (int t = 0; t < size; t++) {
            Monkey curr = dq.front();
            int y = curr.y;
            int x = curr.x;
            int horse = curr.horse;
            dq.pop_front();

            if (y == h-1 && x == w-1)
            {
                isArrived = true;
                break;
            }

            if (horse < k)
            {
                for (int i = 0; i < 8; i++) {
                    int ny = y + hdy[i];
                    int nx = x + hdx[i];

                    if (inRange(ny, nx) && world[ny][nx] != 1 && !visited[ny][nx][horse+1])
                    {
                        visited[ny][nx][horse+1] = true;
                        dq.emplace_back(ny, nx, horse+1);
                    }
                }
            }

            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if (inRange(ny, nx) && world[ny][nx] != 1 && !visited[ny][nx][horse])
                {
                    visited[ny][nx][horse] = true;
                    dq.emplace_back(ny, nx, horse);
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