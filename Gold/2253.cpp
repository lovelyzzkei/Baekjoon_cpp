#include <iostream>

#define MAX_N 10010
#define MAX_SPEED 501
#define INF 1000000007
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int n, m;
bool smallRock[MAX_N];
int cache[MAX_N][MAX_SPEED];

void initCache()
{
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < MAX_SPEED; j++) {
            cache[i][j] = -1;
        }
    }
}

int jump(int curr, int speed)
{
    if (curr == n) return 0;
    if (curr > n || smallRock[curr]) return INF;

    int& ret = cache[curr][speed];
    if (ret != -1) return ret;

    ret = 1 + jump(curr+speed+1, speed+1);
    if (speed >= 1)
        ret = min(ret, 1 + jump(curr+speed, speed));
    if (speed >= 2)
        ret = min(ret, 1 + jump(curr+speed-1, speed-1));

    return ret;
}   


int main(void)
{
    FAST_IO;
    int num;

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> num;
        smallRock[num] = true;
    }
    initCache();

    if (jump(1, 0) >= INF) cout << -1;
    else cout << jump(1, 0);

    return 0;
}