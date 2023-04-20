#include <iostream>

#define INF 1000007

using namespace std;

int cache[51][51][51][51];
int arcade[51][51];
int n, m, c;

void initCache() {

    for (int i = 0; i < 51; i++) {
        for (int j = 0; j < 51; j++) {
            for (int k = 0; k < 51; k++) {
                for (int l = 0; l < 51; l++) {
                    cache[i][j][k][l] = -1;
                }
            }
        }
    }
}

int goArcade(int y, int x, int k, int prev)
{
    if (y > m || x > n) return 0;  
    if (y == m && x == n) 
    {
        int& curr = arcade[y][x];
        if (k == 0 && curr == 0) return 1;
        if (k == 1 && curr > prev) return 1;
        return 0;
        }

    int& ret = cache[y][x][k][prev];

    if (ret != -1) return ret;

    ret = 0;
    int& curr = arcade[y][x];
    if (curr == 0)
    {
        ret = (goArcade(y+1, x, k, prev) % INF + goArcade(y, x+1, k, prev) % INF) % INF;
    }
    else if (curr > prev)
    {
        ret = (goArcade(y+1, x, k-1, curr) % INF + goArcade(y, x+1, k-1, curr) % INF) % INF;
    }

    return ret; 
}


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> c;

    int y, x;
    initCache();

    for (int i = 1; i <= c; i++) {
        cin >> x >> y;
        arcade[y][x] = i;
    }

    for (int i = 0; i <= c; i++) {
        cout << goArcade(1, 1, i, 0) % INF << " ";
    }

    return 0;
}