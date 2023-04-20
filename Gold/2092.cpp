#include <iostream>
#include <memory.h>

#define MAX_T 201
#define MAX_A 4001
#define INF 1000000
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int t, a, s, b;
int cache[MAX_T][MAX_A];
int num[MAX_T];

void initCache()
{
    for (int i = 0; i < MAX_T; i++) 
        for (int j = 0; j < MAX_A; j++)
            cache[i][j] = -1;
}


int makeSet(int max, int len)
{
    if (len == 0) return 1;
    if (len < 0 || max <= 0) return 0;

    int& ret = cache[max][len];
    if (ret != -1) return ret;

    ret = makeSet(max-1, len);
    if (num[max] > 0)
    {
        for (int add = 1; add <= num[max]; add++) {
            ret += makeSet(max-1, len-add) % INF;
        }
    }

    return ret % INF;
}


int main(void)
{
    FAST_IO;
    cin >> t >> a >> s >> b;

    int tmp;
    initCache();
    memset(num, 0, sizeof(num));

    for (int i = 0; i < a; i++) {
        cin >> tmp;
        num[tmp]++;
    }


    int ret = 0;
    for (int i = s; i <= b; i++) {
        ret += makeSet(t, i) % INF;
    }


    // for (int i = 0; i <= t; i++) {
    //     for (int j = 0; j <= a; j++) {
    //         cout << cache[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << ret % INF;

    return 0;
}
