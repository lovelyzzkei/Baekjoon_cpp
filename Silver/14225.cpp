#include <iostream>

#define N 21
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int n, num[N];
bool visited[2000001];

void backtrace(int idx, int sum)
{
    if (idx == n)
        return;
    
    for (int i = idx+1; i < n; i++) {
        int next = sum + num[i];
        visited[next] = true;
        backtrace(i, next);
    }
}

int main(void)
{
    FAST_IO;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        visited[num[i]] = true;
    }

    backtrace(-1, 0);

    int ans = 1;
    while (visited[ans])
        ans++;

    cout << ans;
    return 0;    
}