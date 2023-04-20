#include <iostream> 
#include <string>
#include <math.h>
#include <algorithm>

#define MAX 1001

using namespace std;

string a, b, ret;
int dp[MAX][MAX];

void initArray()
{
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            dp[i][j] = 0;
        }
    }
}


int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> a;
    cin >> b;

    initArray();
    for (int i = 1; i <= (int)a.length(); i++) {
        for (int j = 1; j <= (int)b.length(); j++) {
            if (a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    cout << dp[a.length()][b.length()] << endl;

    ret = "";
    int i = a.size();
    int j = b.size();

    while (true)
    {
        if (dp[i][j] == 0) break;
        
        if (dp[i-1][j] == dp[i][j]) {
            i--;
            continue;
        }

        if (dp[i][j-1] == dp[i][j]) {
            j--;
            continue;
        }
        
        ret += a[i-1];
        i--;
        j--;
    }

    reverse(ret.begin(), ret.end());
    cout << ret;

    return 0;
}