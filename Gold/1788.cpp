#include <iostream>
#include <memory.h>

#define MAX 1000001
#define INF 1000000000
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int n;
int posCache[MAX];
int negCache[MAX];


int posFibonacci(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    int& ret = posCache[n];
    if (ret != -1) return ret;
    return ret = (posFibonacci(n-2)%INF + posFibonacci(n-1)%INF) % INF;
}


int negFibonacci(int n)
{
    if (n == 0) return 0;
    if (n == -1) return 1;
    int& ret = negCache[abs(n)];
    if (ret != -1) return ret;
    return ret = (negFibonacci(n+2)%INF - negFibonacci(n+1)%INF) % INF;
}

int main(void)
{
    FAST_IO;
    for (int i = 0; i < MAX; i++) {
        posCache[i] = -1;
        negCache[i] = -1;
    }

    posCache[0] = 0, posCache[1] = 1;
    negCache[0] = 0, negCache[1] = 1;

    cin >> n;

    for (int i = 0; i <= abs(n); i++) {
        posFibonacci(i);
        negFibonacci(-i);
    }
    
    int fn;
    if (n > 0) fn = posFibonacci(n);
    else fn = negFibonacci(n);

    if (fn > 0) cout << 1 << endl;
    else if (fn == 0) cout << 0 << endl;
    else cout << -1 << endl;

    cout << abs(fn) % INF << endl;

    return 0;    
}