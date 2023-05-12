#include <iostream>
#include <queue>
#include <deque>
#include <string>
#include <memory.h>

#define W 21
#define S 3000
#define INF 1000001
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int w, h, dirty, cache[W][W][S], arr[W][W];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

struct Robot {
    int y;
    int x;
    int numOfClean;
    int move;
    int visited;
    Robot(int _y, int _x, int _n, int _m, int v) : y(_y), x(_x), numOfClean(_n), move(_m), visited(v) {}
};

struct cmp {
    bool operator()(Robot a, Robot b) {
        return a.move > b.move;
    }
};

bool inRange(int y, int x)
{
    return (0 <= y && y < h) && (0 <= x && x < w);
}

int main(void)
{
    FAST_IO;
    while (true) {
        cin >> w >> h;
        if (w == 0 && h == 0)
            break;

        string s;
        int y, x;
        dirty = 0;
        
        for (int i = 0; i < h; i++) {
            cin >> s;
            for (int j = 0; j < w; j++) {
                if (s[j] == '.') arr[i][j] = 0;
                else if (s[j] == 'o')
                {
                    y = i; x = j;
                    arr[i][j] = 0;
                }
                else if (s[j] == '*') 
                {
                    dirty++;
                    arr[i][j] = dirty;
                }
                else arr[i][j] = -1;
            }
        }
        
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                for (int k = 0; k < S; k++) {
                    cache[i][j][k] = INF;
                }
            }
        }
        

        priority_queue<Robot, vector<Robot>, cmp> pq;
        pq.emplace(y, x, 0, 0, 0);
        cache[y][x][0] = 0;

        int ans = -1;
        while (!pq.empty()) {
            Robot curr = pq.top();
            int cy = curr.y;
            int cx = curr.x;
            int clean = curr.numOfClean;
            int move = curr.move;
            int visited = curr.visited;
            pq.pop();

            // cout << cy << " " << cx << " " << clean << " " << move << " " << visited << endl;

            if (clean == dirty)
            {
                ans = move;
                break;
            }

            if (cache[cy][cx][visited] < move)
                continue;

            for (int i = 0; i < 4; i++) {
                int ny = cy + dy[i];
                int nx = cx + dx[i];

                if (inRange(ny, nx) && arr[ny][nx] != -1)
                {
                    if (arr[ny][nx] > 0)
                    {
                        if (((1 << arr[ny][nx]) & visited) == 0 && move + 1 < cache[ny][nx][(visited|(1<<arr[ny][nx]))])
                        {
                            cache[ny][nx][(visited|(1<<arr[ny][nx]))] = move+1;
                            pq.emplace(ny, nx, clean+1, move+1, (visited|(1<<arr[ny][nx])));
                        }
                        else if (move + 1 < cache[ny][nx][visited])
                        {
                            cache[ny][nx][visited] = move + 1;
                            pq.emplace(ny, nx, clean, move+1, visited);
                        }
                    }
                    if (arr[ny][nx] == 0 && move + 1 < cache[ny][nx][visited])
                    {
                        cache[ny][nx][visited] = move+1;
                        pq.emplace(ny, nx, clean, move+1, visited);
                    }
                }
            }
            
        }

        cout << ans << endl;
    }
}