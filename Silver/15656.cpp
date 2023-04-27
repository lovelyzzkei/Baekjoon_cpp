#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, num;
string str;
vector<int> v, s;

void select(int cnt)
{   
    if (cnt == 0)
    {
        for (auto n : s) 
            str += (to_string(n) + " ");
        str += "\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        s[m-cnt] = v[i];
        select(cnt-1);
        s[m-cnt] = 0;
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
    s.resize(m);
    select(m);

    cout << str;
    return 0;
}