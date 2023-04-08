#include <iostream>

#define MAX_N 51
#define MAX_D 101
#define lld long long int
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int n, d;
lld character[MAX_N], power[MAX_N];
lld cache[MAX_N][MAX_D][MAX_D];

void input()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> character[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> power[i];
    }
    cin >> d;
}

void init_cache()
{
    for (int i = 0; i < MAX_N; i++) 
        for (int j = 0; j < MAX_D; j++)
            for (int k = 0; k < MAX_D; k++)
                cache[i][j][k] = -1;
}


lld train(int l, int curr, int d)
{
    if (l == n) return (character[l] + curr) * power[l];
    lld &ret = cache[l][curr][d];
    if (ret != -1) return ret;

    ret = 0;
    for (int day = 0; day <= d; day++) {
        if (character[l] + curr >= day) {
            ret = max(ret, (character[l] + curr - day)*power[l] + train(l+1, day, d-day));
        }
    }

    return ret;
}


int main(void)
{
    input();
    init_cache();

    cout << train(1, 0, d);    
    return 0;
}
