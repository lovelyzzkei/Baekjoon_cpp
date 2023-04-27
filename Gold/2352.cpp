#include <iostream>
#include <algorithm>

#define N 40001
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int n, lis[N], port[N];

int main(void)
{
    FAST_IO;
    cin >> n;

    int len = 0;
    for (int i = 0; i < n; i++) {
        cin >> port[i];
        int target = port[i];
        auto pos = lower_bound(lis, lis+len, target);
        *pos = target;
        if (pos == lis+len)
            len++;
    }

    cout << len;
    return 0;
}