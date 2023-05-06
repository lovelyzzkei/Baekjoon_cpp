#include <iostream>

#define N 301
#define M 301
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, r, arr[N][M];

void rotateCounterClockWise(int r, int c, int sr, int sc)
{
    int tmp = arr[sr][sc];
    for (int i = 0; i < c-1; i++) {
        arr[sr][sc+i] = arr[sr][sc+i+1];
    }
    for (int i = 0; i < r-1; i++) {
        arr[sr+i][sc+c-1] = arr[sr+i+1][sc+c-1];
    }
    for (int i = c-1; i > 0; i--) {
        arr[sr+r-1][sc+i] = arr[sr+r-1][sc+i-1];
    }
    for (int i = r-1; i > 0; i--) {
        arr[sr+i][sc] = arr[sr+i-1][sc];
    }
    arr[sr+1][sc] = tmp;
}

void rccw(int row, int col)
{   
    int sr = 0, sc = 0;
    while (row != 0 && col != 0) {
        int numOfRotate = r % ((row+col-2)*2);
        for (int i = 0; i < numOfRotate; i++) {
            rotateCounterClockWise(row, col, sr, sc);
        }

        sr++;
        sc++;
        row -= 2;
        col -= 2;
    }
}

int main(void)
{
    FAST_IO;
    cin >> n >> m >> r;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];    
        }
    }

    rccw(n, m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}