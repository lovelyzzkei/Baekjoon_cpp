#include <iostream>
#include <stdlib.h>

using namespace std;

int n, m;

bool inRange(int x, int y) {
    return (0 <= x && x < n) && (0 <= y && y < m);
}

int main() {
    int k;
    int x1, y1, x2, y2;
    long long roads[101][101];
    bool isConstruct[101][101];

    cin.sync_with_stdio(false);
    cin >> n >> m;
    cin >> k;

    for (int i = 0; i < k; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        isConstruct[x1][y1] = true;
        isConstruct[x2][y2] = true;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            bool leftToRight = true;
            bool bottomToUp = true;
            if (!inRange(i, j-1) || (inRange(i, j-1) && isConstruct[i][j] && isConstruct[i][j-1])) {
                leftToRight = false;
            } 
            if (!inRange(i-1, j) || (inRange(i-1, j) && isConstruct[i][j] && isConstruct[i-1][j])) {
                bottomToUp = false;
            } 
            
            if (leftToRight) roads[i][j] += roads[i][j-1];
            if (bottomToUp) roads[i][j] += roads[i-1][j];
        }
    }

    cout << roads[n-1][m-1] << endl;

    return 0;
}