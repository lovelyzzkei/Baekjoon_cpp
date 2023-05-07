#include <iostream>
#include <string>

#define N 51
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, A[N][N], B[N][N];

void flip(int r, int c)
{
    for (int i = r; i < r+3; i++) {
        for (int j = c; j < c+3; j++) {
            A[i][j] = (A[i][j] ^ 1);
        }
    }
}

int main(void)
{
    FAST_IO;
    cin >> n >> m;

    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++) {
            A[i][j] = s[j] - '0';
        }
    }

    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++) {
            B[i][j] = s[j] - '0';
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] != B[i][j])
            {
                if (i + 3 > n || j + 3 > m)
                {
                    cout << -1;
                    return 0;
                }
                flip(i, j);
                cnt++;
            }
        }
    }

    cout << cnt;
    return 0;
    
}