#include <iostream>
#include <memory.h>

#define S 51
#define INF 1000000007
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

long long int s, cache[S][S][S][S];
int cases[7][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}, {1, 1, 0}, {1, 0, 1}, {0, 1, 1}, {1, 1, 1}};

long long int acka(int ss, int a, int b, int c)
{
    if (ss == s)
    {
        if (a == 0 && b == 0 && c == 0) return 1;
        else return 0;
    }

    long long int &ret = cache[ss][a][b][c];
    if (ret != -1) return ret;

    ret = 0;
    for (int i = 0; i < 7; i++) {
        if (a >= cases[i][0] && b >= cases[i][1] && c >= cases[i][2])
        {
            ret += (acka(ss+1, a-cases[i][0], b-cases[i][1], c-cases[i][2]) % INF);
        }
    }
    return ret % INF;
}

int main(void)
{
    FAST_IO;

    int a, b, c;
    cin >> s >> a >> b >> c;
    memset(cache, -1, S*S*S*S*sizeof(long long int));

    cout << acka(0, a, b, c);
    return 0;
}