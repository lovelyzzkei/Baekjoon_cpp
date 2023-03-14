#include <iostream>

#define MAX 100001

using namespace std;

int main()
{
    int n, ret;
    int left[MAX], right[MAX], dp[MAX];

    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (num == 1) {
            if (i == 0) {
                left[i] = 1; 
                right[i] = 0;
            }
            else {
                left[i] = left[i-1] + 1;
                right[i] = right[i-1];
            }
        }
        else {
            if (i == 0) {
                right[i] = 1; 
                left[i] = 0;
            }
            else {
                right[i] = right[i-1] + 1;
                left[i] = left[i-1];
            }
        }
    }

    dp[0] = 1;
    ret = dp[0];
    for (int i = 1; i < n; i++) {
        dp[i] = max(abs(left[i]-right[i]), 1);
        ret = max(ret, dp[i]);
    }

    for (int i = 0; i < n; i++) {
        cout << dp[i] << " " ;
    }
    cout<< endl;
    for (int i = 0; i < n; i++) {
        cout << left[i] << " " ;
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << right[i] << " " ;
    }
    cout << endl;

    cout << ret;

    return 0;
}