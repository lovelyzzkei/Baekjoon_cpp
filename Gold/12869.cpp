#include <iostream>
#include <memory.h>
#include <algorithm>

#define N 3
#define MAX_DAM 61
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int n, cache[MAX_DAM][MAX_DAM][MAX_DAM], scv[N];
int damage[][3] = {{1, 3, 9}, {1, 9, 3}, {3, 1, 9}, {3, 9, 1}, {9, 1, 3}, {9, 3, 1}};

int mutalisk(int a, int b, int c)
{
    if (a == 0 && b == 0 && c == 0)
        return 0;

    int &ret = cache[a][b][c];
    if (ret != -1) 
        return ret;
    
    ret = 100000;
    for (int i = 0; i < 6; i++) {
        int next[3];
        next[0] = max(0, a-damage[i][0]);
        next[1] = max(0, b-damage[i][1]);
        next[2] = max(0, c-damage[i][2]);

        sort(next, next+3);

        ret = min(ret, mutalisk(next[0], next[1], next[2]) + 1);
    }

    return ret;
}


int main(void)
{
    FAST_IO;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> scv[i];
    }

    sort(scv, scv+3);
    memset(cache, -1, MAX_DAM*MAX_DAM*MAX_DAM*sizeof(int));

    cout << mutalisk(scv[0], scv[1], scv[2]);
    return 0;
}