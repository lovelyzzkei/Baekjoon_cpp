#include <iostream>
#include <stdlib.h>
#include <vector>
#include <utility>

using namespace std;

int n, m;
long long int cache[101][101];
vector<vector<int>> construction;

bool inRange(int x, int y) {
    return (0 <= x && x <= n) && (0 <= y && y <= m);
}

bool isConstruct(int y1, int x1, int y2, int x2)
{
    for (int i = 0; i < construction.size(); i++) {
        if ((construction[i][0] == y1 && construction[i][1] == x1 \
            && construction[i][2] == y2 && construction[i][3] == x2) || \
            (construction[i][0] == y2 && construction[i][1] == x2 \
            && construction[i][2] == y1 && construction[i][3] == x1))
            return true;
    }
    return false;
}


long long int route(int x, int y)
{
    if (x == n && y == m) return 1;
    if (x > n || y > m) return 0;

    long long int& ret = cache[y][x];
    if (ret != -1) return ret;

    ret = 0;
    if (inRange(x, y+1) && !isConstruct(y, x, y+1, x))
        ret += route(x, y+1);

    if (inRange(x+1, y) && !isConstruct(y, x, y, x+1))
        ret += route(x+1, y);

    return ret;
}


int main() {
    int k;
    int x1, y1, x2, y2;

    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    cin >> k;

    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++) {
            cache[i][j] = -1;
        }
    }

    for (int i = 0; i < k; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        vector<int> tmp;
        tmp.push_back(y1);
        tmp.push_back(x1);
        tmp.push_back(y2);
        tmp.push_back(x2);
        construction.push_back(tmp);
    }

    cout << route(0, 0);

    return 0;
}