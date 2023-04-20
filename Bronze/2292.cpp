#include <iostream>
#include <cmath>

#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int n;

int main(void)
{
    FAST_IO;
    cin >> n;

    int ret = 1;
    while (3*pow(ret,2)-3*ret+1 < n) 
        ret++;
    
    cout << ret;
    return 0;
}