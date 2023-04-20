#include <iostream>
#include <string>
#include <memory.h>

using namespace std;

string X, Y;
int a, b, c;
int cache[3001][3001];

int score(int x, int y)
{
    if (x == X.size() && y == Y.size()) return 0;
    if (x == X.size()) return b*(Y.size() - y);
    if (y == Y.size()) return b*(X.size() - x);
    
    int& ret = cache[x][y];
    if (ret != -1) return ret;

    ret = 0;
    if (X[x] == Y[y])
        ret = a + score(x+1, y+1);
    else
        ret = max(c + score(x+1, y+1), b + max(score(x+1, y), score(x, y+1)));

    return ret;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b >> c;
    cin >> X;
    cin >> Y;

    memset(cache, -1, sizeof(cache));
    cout << score(0, 0);
    return 0;
}