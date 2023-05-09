#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <memory.h>

#define H 102
#define INF 100001
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int t, h, w, prison[H][H], cache[H][H], ret[H][H];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
vector<pair<int, int>> p;

struct Prisoner {
    int y, x, door;
    Prisoner(int cy, int cx, int d) : y(cy), x(cx), door(d) {}
};

struct cmp {
    bool operator()(Prisoner a, Prisoner b)
    {
        return a.door > b.door;
    }
};

bool inRange(int y, int x)
{
    return (0 <= y && y <= h+1) && (0 <= x && x <= w+1);
}

void input()
{
    p.clear();
    memset(ret, 0, H*H*sizeof(int));
    memset(prison, 0, H*H*sizeof(int));

    string s;
    for (int i = 1; i <= h; i++) {
        cin >> s;
        for (int j = 1; j <= w; j++) {
            if (s[j-1] == '*') prison[i][j] = -1;
            else if (s[j-1] == '#') prison[i][j] = 1;
            else if (s[j-1] == '.') prison[i][j] = 0;
            else
            {
                p.push_back(make_pair(i, j));
                prison[i][j] = 0;
            }
        }
    }

    for (int i = 0; i <= h+1; i++) {
        for (int j = 0; j <= w+1; j++) {
            cache[i][j] = INF;
        }
    }
}

void bfs(int y, int x)
{
    for (int i = 0; i <= h+1; i++) {
        for (int j = 0; j <= w+1; j++) {
            cache[i][j] = INF;
        }
    }
    
    priority_queue<Prisoner, vector<Prisoner>, cmp> pq;
    pq.emplace(y, x, 0);
    cache[y][x] = 0;

    while (!pq.empty()) {
        Prisoner curr = pq.top();
        int cy = curr.y;
        int cx = curr.x;
        int cdoor = curr.door;
        pq.pop();

        if (cache[cy][cx] < cdoor)
            continue;

        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (inRange(ny, nx) && prison[ny][nx] != -1 && cdoor + prison[ny][nx] < cache[ny][nx])
            {
                cache[ny][nx] = cdoor + prison[ny][nx];
                pq.emplace(ny, nx, cache[ny][nx]);
            }
        }
    }

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (prison[i][j] != -1) 
                ret[i][j] += cache[i][j];
        }
    }
}


int main(void)
{
    FAST_IO;
    cin >> t;
    for (int _ = 0; _ < t; _++) {
        cin >> h >> w;
        input();
        
        bfs(p[0].first, p[0].second);       
        bfs(p[1].first, p[1].second);
        bfs(0, 0);

        int ans = INF;
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                if (prison[i][j] == -1)
                    continue;
                
                if (prison[i][j] == 1)
                    ans = min(ans, ret[i][j]-2);
                else   
                    ans = min(ans, ret[i][j]);
            }
        }
        
        cout << ans << endl;
    }

    return 0;
}