#include <iostream>
#include <memory.h>

#define N 51
#define M 1001
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int n, s, m, volume[N], cache[N][M];
bool visited[N][M];

int play(int idx, int v)
{
    if (idx == n)
        return v;
    
    int &ret = cache[idx][v];
    if (ret != -1)
        return ret;

    visited[idx][v] = true;
    if (v - volume[idx] >= 0 && !visited[idx+1][v-volume[idx]])
        ret = max(ret, play(idx+1, v-volume[idx]));
    if (v + volume[idx] <= m && !visited[idx+1][v+volume[idx]])
        ret = max(ret, play(idx+1, v+volume[idx]));

    return ret;
}

int main(void)
{
    FAST_IO;
    cin >> n >> s >> m;
    for (int i = 0; i < n; i++) {
        cin >> volume[i];
    }
    memset(cache, -1, N*M*sizeof(int));

    int ret = play(0, s);
    if (ret == -1)
        cout << -1;
    else   
        cout << ret;

    return 0;
}
