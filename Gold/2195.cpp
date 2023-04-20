#include <iostream>
#include <string>

#define MAX 1001
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int cache[MAX];
string S, P;

void initCache()
{
    for (int i = 0; i < MAX; i++) 
        cache[i] = MAX;
}

int minCopy(int len)
{
    if (len == P.size()) return 0;
    int& ret = cache[len];
    if (ret != MAX) return ret;

    int idx = 1;
    while (len + idx <= P.size() && S.find(P.substr(len, idx)) != string::npos) {
        ret = min(ret, 1 + minCopy(len+idx));
        idx++;
    }

    return ret;
}



int main(void)
{
    FAST_IO;
    cin >> S >> P;
    
    initCache();
    cout << minCopy(0);
    return 0;
}