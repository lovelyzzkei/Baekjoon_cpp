#include <iostream>

#define N 301
#define M 301
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, r, arr[N][M];

void rotateCounterClockWise(int r, int c)
{
    int row = r, col = c;
    int sy = 0, sx = 0;
    while (row != 0 && col != 0) {
        int tmp = arr[sy][sx];
        for (int i = 0; i < col-1; i++) {
            arr[sy][sx+i] = arr[sy][sx+i+1];
        }
        for (int i = 0; i < row-1; i++) {
            arr[sy+i][sx+col-1] = arr[sy+i+1][sx+col-1];
        }

        for (int i = col-1; i > 0; i--) {
            arr[sy+row-1][sx+i] = arr[sy+row-1][sx+i-1];
        }
        for (int i = row-1; i > 0; i--) {
            arr[sy+i][sx] = arr[sy+i-1][sx];
        }
        arr[sy+1][sx] = tmp;

        sy++;
        sx++;
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

    for (int i = 0; i < r; i++) {
        rotateCounterClockWise(n, m);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}