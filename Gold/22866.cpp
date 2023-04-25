#include <iostream>
#include <cstdlib>
#include <stack>
#include <utility>

#define N 100001
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

stack<pair<int, int>> s;
int n, tower[N], ans[N], towerNum[N][2];

int main(void)
{
    FAST_IO;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> tower[i];
        towerNum[i][1] = N;
    }


    for (int i = 1; i <= n; i++) {
        while (!s.empty() && s.top().first <= tower[i]) 
            s.pop();

        ans[i] += (int)s.size();
        if (!s.empty())
        {
            int gap = abs(s.top().second - i);
            if (gap < towerNum[i][1])
            {
                towerNum[i][1] = gap;
                towerNum[i][0] = s.top().second;
            }
            else if (gap == towerNum[i][1] && s.top().second < towerNum[i][0])
            {
                towerNum[i][0] = s.top().second;
            }
        } 
            
        s.push(make_pair(tower[i], i));
    }

    while (!s.empty())
        s.pop();

    for (int i = n; i >= 1; i--) {
        while (!s.empty() && s.top().first <= tower[i]) 
            s.pop();

        ans[i] += (int)s.size();
        if (!s.empty())
        {
            int gap = abs(s.top().second - i);
            if (gap < towerNum[i][1])
            {
                towerNum[i][1] = gap;
                towerNum[i][0] = s.top().second;
            }
            else if (gap == towerNum[i][1] && s.top().second < towerNum[i][0])
            {
                towerNum[i][0] = s.top().second;
            }
        } 

        s.push(make_pair(tower[i], i));
    }
    
    for (int i = 1; i <= n; i++) {
        cout << ans[i];
        if (ans[i] != 0)
            cout << " " << towerNum[i][0];
        if (i != n)
            cout << endl;
    }

    return 0;
}