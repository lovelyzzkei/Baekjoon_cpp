#include <iostream>
#include <vector>
#include <algorithm>

#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, num;
vector<int> v, s;

void select(int idx, int cnt)
{   
    if (cnt == 0)
    {
        for (int i = 0; i < s.size(); i++) {
            cout << s[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int i = idx+1; i < n; i++) {
        s.push_back(v[i]);
        select(i, cnt-1);
        s.pop_back();
    }
}

int main(void)
{
    FAST_IO;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> num;
        v.push_back(num);   
    }

    sort(v.begin(), v.end());
    select(-1, m);

    return 0;
}