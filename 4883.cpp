#include <iostream>
#include <climits>

#define MAX 100001
#define INF 2000000007
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int n;
int cost[MAX][3];
int cache[MAX][3];

void initCache()
{
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < 3; j++)
            cache[i][j] = INF;
}

bool inRange(int y, int x)
{
    return (0 <= y && y < n) && (0 <= x && x < 3);
}

int main(void)
{
    FAST_IO;

    int numTest = 1;
    cin >> n;
    while (n != 0) {
        for (int i = 0; i < n; i++) {
            cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
        }

        initCache();
        cache[0][1] = cost[0][1];

        for (int y = 0; y < n; y++) {
            for (int x = 0; x < 3; x++) {
                int curr = cost[y][x];
                int& ret = cache[y][x];
                if (inRange(y, x-1)) ret = min(ret, cache[y][x-1] + curr);
                if (inRange(y-1, x-1)) ret = min(ret, cache[y-1][x-1] + curr);
                if (inRange(y-1, x)) ret = min(ret, cache[y-1][x] + curr);
                if (inRange(y-1, x+1)) ret = min(ret, cache[y-1][x+1] + curr);                
            }
        }
        cout << numTest++ << ". " << cache[n-1][1] << endl;
        cin >> n;
    }

    return 0;
}