#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

#define N 10001
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int n, tmp, light[N], lis[N], p[N];
unordered_map<int, int> switches, revSwitches;
vector<int> ret;

void backtrace(int idx, int num)
{
    if (idx == -1) return;

    if (p[idx] == num)
    {
        backtrace(idx-1, num-1);
        ret.push_back(revSwitches[light[idx]]);
    }
    else
        backtrace(idx-1, num);
}

int main(void)
{
    FAST_IO;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        switches[tmp] = i;
        revSwitches[i] = tmp;
    }

    for (int i = 0; i < n; i++) {
        cin >> tmp;
        light[i] = switches[tmp];
    }


    int len = 0;
    for (int i = 0; i < n; i++) {
        int target = light[i];
        auto pos = lower_bound(lis, lis+len, target);
        *pos = target;
        p[i] = distance(lis, pos)+1;

        if (pos == lis+len)
            len++;
    }

    cout << len << endl;
    backtrace(n-1, len);
    sort(ret.begin(), ret.end());
    for (auto n: ret)
        cout << n << " ";
    return 0;
}