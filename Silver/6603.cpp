#include <iostream>
#include <vector>
#include <string>

#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

string ans;
int k, num[50];
vector<int> lotto;

void backtrace(int curr, int cnt)
{
    if (cnt == 6)
    {
        for (auto n : lotto) {
            ans += to_string(n);
            ans += " ";
        }
        ans += "\n";
    }

    for (int i = curr + 1; i < k; i++) {
        lotto.push_back(num[i]);
        backtrace(i, cnt+1);
        lotto.pop_back();
    }
}

int main(void)
{
    FAST_IO;

    ans = "";
    while (true) {
        cin >> k;
        if (k == 0) 
            break;
        
        for (int i = 0; i < k; i++) 
            cin >> num[i];

        backtrace(-1, 0);
        ans += "\n";
    }
    cout << ans;
    return 0;
}