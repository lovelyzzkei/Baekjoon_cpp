#include <iostream>
#include <memory.h>

#define L 5001  
#define INF 1000000007
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

long long int t, l, cache[L];

int main(void)
{
    FAST_IO;
    memset(cache, 0, L*sizeof(long long int));

    cache[0] = 1;
    for (int len = 0; len < L; len+=2) {
        for (int i = 2; i <= len; i += 2) {
            cache[len] += cache[i-2]*cache[len-i];
            cache[len] %= INF;
        }
    }

    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> l;
        cout << cache[l] << endl;
    }

    return 0;
}