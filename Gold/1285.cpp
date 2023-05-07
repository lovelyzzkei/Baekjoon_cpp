#include <iostream>
#include <vector>
#include <string>
#include <memory.h>

#define N 21
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int n, coin[N][N], ans = N*N;

void flip(int idx)
{
    for (int i = 0; i < n; i++) {
        coin[idx][i] = (coin[idx][i] ^ 1);
    }
}

void backtrack(int row)
{
    if (row == n)
    {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int t = 0;
            for (int j = 0; j < n; j++) {
                if (coin[j][i]) t++; 
            }
            cnt += min(t, n-t);
        }
        ans = min(ans, cnt);
        return;
    }

    backtrack(row+1);

    flip(row);
    backtrack(row+1);
    flip(row);
}

int main(void)
{
    FAST_IO;
    cin >> n;

    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < n; j++) {
            if (s[j] == 'H') coin[i][j] = 0;
            else coin[i][j] = 1;
        }
    }   


    backtrack(0);
    cout << ans;
    return 0;
}