#include <iostream>
#include <deque>

#define N 5001
#define INF 100001
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int n, arr[N], cache[N][N];

int palindrome(int l, int r)
{
    if (l >= r)
        return 0;
    
    int &ret = cache[l][r];
    if (ret != INF)
        return ret;

    if (arr[l] == arr[r])
        ret = min(ret, palindrome(l+1, r-1));
    else
        ret = min(ret, min(palindrome(l+1, r)+1, palindrome(l, r-1)+1));
    return ret;
}

int main(void)
{
    FAST_IO;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cache[i][j] = INF;
        }
    }

    cout << palindrome(0, n-1);
    return 0;
}