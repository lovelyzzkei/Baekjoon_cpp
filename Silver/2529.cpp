#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <memory.h>

#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int k;
long long int minAns, maxAns;
bool visited[10];
string sign[11], minStr, maxStr;
vector<int> ans;

void backtrace(int cnt)
{
    if (cnt == k+1)
    {
        long long int t = 0;
        string tmp;
        for (int i = 0; i <= k; i++) {
            tmp += to_string(ans[i]);
            t += pow(10, i)*ans[k-i];
        }

        if (t < minAns)
        {
            minAns = t;
            minStr = tmp;
        }
        if (t > maxAns)
        {
            maxAns = t;
            maxStr = tmp;
        }
        return;
    }

    for (int i = 0; i <= 9; i++) {
        if (visited[i])
            continue;

        
        if (ans.empty() || (cnt > 0 && !sign[cnt].compare("<") && !ans.empty() && ans.back() < i) || (cnt > 0 && !sign[cnt].compare(">") && !ans.empty() && ans.back() > i))
        {
            ans.push_back(i);
            visited[i] = true;
            backtrace(cnt+1);
            ans.pop_back();
            visited[i] = false;
        }
    }
}

int main(void)
{
    FAST_IO;
    cin >> k;
    for (int i = 1; i <= k; i++)
        cin >> sign[i];
    
    memset(visited, 0, 10*sizeof(bool));

    minAns = 100000000000;
    maxAns = -1;
    backtrace(0);
    
    cout << maxStr << endl;
    cout << minStr;
    return 0;
}