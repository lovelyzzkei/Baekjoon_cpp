#include <iostream>
#include <memory.h>
#include <climits>
#include <vector>

#define N 21
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int n, ret, ability[N][N];
bool team[N];

void teamSplit(int idx, int num)
{
    if (num == 0)
    {
        int aSum = 0, bSum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (team[i] && team[j]) aSum += ability[i][j];
                else if (!team[i] && !team[j]) bSum += ability[i][j];
            }
        }

        ret = min(ret, abs(aSum-bSum));
    }

    for (int i = idx+1; i < n; i++) {
        if (!team[i])
        {
            team[i] = true;
            teamSplit(i, num-1);
            team[i] = false;
        }
    }
}

int main(void)
{
    FAST_IO;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> ability[i][j];
        }
    }
    memset(team, 0, N*sizeof(bool));

    ret = INT_MAX;
    for (int i = 1; i <= (int)n/2; i++) {
        teamSplit(-1, i);
    }

    cout << ret;
    return 0;
}