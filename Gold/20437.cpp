#include <iostream>
#include <cstring>
#include <utility>
#include <vector>

#define MAX_W 10001
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int t, k;
int alphabet[26];
string w;

int ctoi(char c)
{
    return c - 'a';
}


int main(void)
{
    FAST_IO;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> w >> k;

        int len = (int)w.size();
        int minLen = MAX_W;
        int maxLen = -1;

        for (int i = 0; i < len; i++) {
            alphabet[ctoi(w[i])]++;
        }

        for (int i = 0; i < len; i++) {
            char curr = w[i];
            if (alphabet[ctoi(curr)] < k)
                continue;

            int count = 0;
            for (int j = i; j < len; j++) {
                if (curr == w[j])
                    count++;

                if (count == k)
                {
                    minLen = min(minLen, j-i+1);
                    maxLen = max(maxLen, j-i+1);
                    break;
                }
            }
        }


        
        if (minLen == MAX_W || maxLen == -1)
            cout << -1 << endl;
        else
            cout << minLen << " " << maxLen << endl;
    }

    return 0;
}