/*
    Date: 2023/03/15
    Name: 2631 - 줄세우기
    Category: Dynamic Programming
    Key: Longest Increasing Sequence
*/

#include <iostream>

#define MAX 201

using namespace std;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;

    int students[MAX], lcs[MAX];
    for (int i = 1; i <= n; i++) {
        cin >> students[i];
        lcs[i] = 1;
    }

    lcs[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= i-1; j++) {
            if (students[i] >= students[j]) {
                lcs[i] = max(lcs[i], lcs[j] + 1);
            }
        }
    }

    int maxLen = 0;
    for (int i = 1; i <= n; i++) {
        maxLen = max(maxLen, lcs[i]);
        // cout << lcs[i] << " ";
    }
    // cout << endl;

    cout << n - maxLen; 

    return 0;
}