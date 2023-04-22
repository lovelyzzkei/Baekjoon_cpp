#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <unordered_map>
#include <utility>

#define N 20001
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int n;
int length[N];
vector<string> words;
vector<pair<string, int>> sorted;

void getInput()
{
    cin >> n;

    string input;
    for (int i = 0; i < n; i++) {
        cin >> input;
        words.push_back(input);
        sorted.push_back(make_pair(input, i));
    }
}

int comparePrefix(const string &a, const string &b)
{
    int ret = 0, aptr = 0, bptr = 0;
    while (aptr < (int)a.size() && bptr < (int)b.size() && a[aptr] == b[bptr])
    {
        ret++;
        aptr++;
        bptr++;
    }

    return ret;
}


int main(void)
{
    FAST_IO;
    getInput();

    sort(sorted.begin(), sorted.end());

    int maxCommonCnt = -1;
    for (int i = 0; i < n-1; i++) {
        int commonPrefix = comparePrefix(sorted[i].first, sorted[i+1].first);

        maxCommonCnt = max(maxCommonCnt, commonPrefix);

        length[sorted[i].second] = max(commonPrefix, length[sorted[i].second]);
        length[sorted[i+1].second] = max(commonPrefix, length[sorted[i+1].second]);
    }

    int first = -1;
    string common;
    for (int i = 0; i < n; i++) {
        if (first == -1)
        {
            if (length[i] == maxCommonCnt)
            {
                cout << words[i] << endl;
                first = i;
                common = words[i].substr(0, maxCommonCnt);
            }
        }
        else
        {
            if (length[i] == maxCommonCnt &&!(words[i].substr(0, maxCommonCnt)).compare(common))
            {
                cout << words[i];
                break;
            }
        }
    }

    return 0;
}
