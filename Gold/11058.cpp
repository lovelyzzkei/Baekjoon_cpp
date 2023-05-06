#include <iostream>
#include <memory.h>
#include <algorithm>

#define N 101
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

long long int n, cache[N];

int main(void)
{
    FAST_IO;
    cin >> n;

    for (int i = 1; i <= 6; i++) 
        cache[i] = i;

    for (int i = 7; i <= n; i++) {
        for (int j = 3; i-j > 0; j++) {
            cache[i] = max(cache[i], (j-1)*cache[i-j]);
        }
    }
    cout << cache[n];
    return 0;
}