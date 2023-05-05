#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

#define N 51
#define K 27
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int n, k, tmp;
int words[N];
int alphabet[21] = {1, 3, 4, 5, 6, 7, 9, 10, 11, 12, 14, 15, 16, 17, 18, 20, 21, 22, 23, 24, 25};
vector<int> cases;

void getAllCases(int cnt, int idx)
{
    if (cnt == k-5)
    {
        cases.push_back(tmp);
        return;
    }

    for (int i = idx+1; i < 21; i++) {
        tmp = tmp + (1 << alphabet[i]);
        getAllCases(cnt+1, i);
        tmp = tmp - (1 << alphabet[i]);
    }
}


int main(void)
{
    FAST_IO;
    cin >> n >> k;

    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;

        int num = 0;
        set<char> ss(s.begin(), s.end());
        for (auto it = ss.begin(); it != ss.end(); it++) {
            num = num | (1 << (*it - 'a'));
        }
        words[i] = num;
    }

    if (k < 5)
    {
        cout << 0;
        return 0;
    }

    tmp = 0;
    getAllCases(0, -1);

    int ret = 0;
    for (int c : cases) {
        c = c | (1 << 0);
        c = c | (1 << 2);
        c = c | (1 << 8);
        c = c | (1 << 13);
        c = c | (1 << 19);
        
        int match = 0;
        for (int i = 0; i < n; i++) {
            if ((c ^ words[i]) == 0 || (words[i] | (c ^ words[i])) == c)
            {
                match++;
            }
        }

        ret = max(ret, match);
    }

    cout << ret;

    return 0;
}