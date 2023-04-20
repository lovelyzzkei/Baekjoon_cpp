#include <iostream>
#include <string>

#define INF 10000001

using namespace std;

string A, B;
int cache[1001][1001];

void initCache()
{
    for (int i = 0; i < 1001; i++) {
        for (int j = 0; j < 1001; j++) {
            cache[i][j] = INF;
        }
    }
}

int edit(int a, int b)
{
    if (a == A.size() && b == B.size()) return 0;
    if (a == A.size()) return B.size() - b;
    if (b == B.size()) return A.size() - a;

    int& ret = cache[a][b];
    if (ret != INF) return ret;

    if (A[a] == B[b])
        ret = edit(a+1, b+1);
    else
        ret = min(1 + edit(a, b+1), min(1 + edit(a+1, b+1), 1 + edit(a+1, b)));

    return ret;
}


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    initCache();

    cin >> A >> B;
    cout << edit(0, 0);

    return 0;
}