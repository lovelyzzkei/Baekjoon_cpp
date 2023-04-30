#include <iostream>

#define N 101
#define M 101
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, r, arr[N][M], row, col;


void swap(int r1, int c1, int r2, int c2)
{
    int tmp = arr[r1][c1];
    arr[r1][c1] = arr[r2][c2];
    arr[r2][c2] = tmp;
}


void topBottomFlip()
{
    for (int i = 0; i < (int)(n/2); i++) 
        for (int j = 0; j < m; j++) 
            swap(i, j, n-1-i, j);
}

void leftRightFlip()
{
    for (int i = 0; i < (int)(m/2); i++)
        for (int j = 0; j < n; j++) 
            swap(j, i, j, m-1-i);
}

void rotateRight(int startRow, int startCol, int endRow, int endCol)
{
    int tmp[N][M];
    for (int i = startCol; i < endCol; i++) {
        for (int j = startRow; j < endRow; j++) {
            tmp[i][j] = arr[n-1-j][i];
        }
    }

    for (int i = startCol; i < endCol; i++) {
        for (int j = startRow; j < endRow; j++) {
            arr[i][j] = tmp[i][j];
        }
    }
}

void rotateLeft(int startRow, int startCol, int endRow, int endCol)
{
    int tmp[N][M];
    for (int i = startCol; i < endCol; i++) {
        for (int j = startRow; j < endRow; j++) {
            tmp[i][j] = arr[j][m-1-i];
        }
    }

    for (int i = startCol; i < endCol; i++) {
        for (int j = startRow; j < endRow; j++) {
            arr[i][j] = tmp[i][j];
        }
    }
}

void rotateRightQuarter()
{
    int tmp[N][M];
    for (int i = 0; i < n/2; i++) {
        for (int j = 0; j < m/2; j++) {
            tmp[i][j] = arr[i][j];
            arr[i][j] = arr[i+n/2][j];
        }
    }

    for (int i = n/2; i < n; i++) {
        for (int j = 0; j < m/2; j++) {
            arr[i][j] = arr[i][j+m/2];
        }
    }

    for (int i = n/2; i < n; i++) {
        for (int j = m/2; j < m; j++) {
            arr[i][j] = arr[i-n/2][j];
        }
    }

    for (int i = 0; i < n/2; i++) {
        for (int j = m/2; j < m; j++) {
            arr[i][j] = tmp[i][j-m/2];
        }
    }
}

void rotateLeftQuarter()
{
    int tmp[N][M];
    for (int i = 0; i < n/2; i++) {
        for (int j = 0; j < m/2; j++) {
            tmp[i][j] = arr[i][j];
            arr[i][j] = arr[i][j+m/2];
        }
    }

    for (int i = 0; i < n/2; i++) {
        for (int j = m/2; j < m; j++) {
            arr[i][j] = arr[i+n/2][j];
        }
    }

    for (int i = n/2; i < n; i++) {
        for (int j = m/2; j < m; j++) {
            arr[i][j] = arr[i][j-m/2];
        }
    }

    for (int i = n/2; i < n; i++) {
        for (int j = 0; j < m/2; j++) {
            arr[i][j] = tmp[i-n/2][j];
        }
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

    int op;
    for (int i = 0; i < r; i++) {
        cin >> op;
        switch (op) {
            case 1:
                topBottomFlip();
                break;
            case 2:
                leftRightFlip();
                break;
            case 3:
                rotateRight(0, 0, n, m);
                swap(n, m);
                break;
            case 4:
                rotateLeft(0, 0, n, m);
                swap(n, m);
                break;
            case 5:
                rotateRightQuarter();
                break;
            case 6:
                rotateLeftQuarter();
                break;
        } 
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}