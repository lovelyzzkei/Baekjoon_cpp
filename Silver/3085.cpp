#include <iostream>

#define N 51
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int n, candy[N][N];
int dy[] = {0, 1};
int dx[] = {1, 0};

bool inRange(int y, int x)
{
    return (0 <= y && y < n) && (0 <= x && x < n);
}

void swap(int y1, int x1, int y2, int x2)
{
    int tmp = candy[y1][x1];
    candy[y1][x1] = candy[y2][x2];
    candy[y2][x2] = tmp;
}

int maxContinuousPart()
{
    int row = 0;
    for (int i = 0; i < n; i++) {
        int ptr = 0, idx = 0;
        while (ptr < n) {
            while (ptr < n && idx < n && candy[i][ptr] == candy[i][idx]) 
                idx++;
            
            row = max(row, idx-ptr);
            ptr = idx;
        }
    }

    int col = 0;
    for (int i = 0; i < n; i++) {
        int ptr = 0, idx = 0;
        while (ptr < n) {
            while (ptr < n && idx < n && candy[ptr][i] == candy[idx][i]) 
                idx++;
            
            col = max(col, idx-ptr);
            ptr = idx;
        }
    }

    return max(row, col);
}

int main(void)
{
    FAST_IO;
    cin >> n;

    char c;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> c;
            if (c == 'C') candy[i][j] = 1;
            else if (c == 'P') candy[i][j] = 2;
            else if (c == 'Z') candy[i][j] = 3;
            else if (c == 'Y') candy[i][j] = 4;
        }
    }

    int ret = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int curr = candy[i][j];
            for (int k = 0; k < 2; k++) {
                int ni = i + dy[k];
                int nj = j + dx[k];
                if (!inRange(ni, nj))
                    continue;

                int next = candy[ni][nj];
                if (curr != next)
                {
                    swap(i, j, ni, nj);
                    ret = max(ret, maxContinuousPart());
                    swap(ni, nj, i, j);
                }
            }
        }
    }

    cout << ret;
    return 0;
}