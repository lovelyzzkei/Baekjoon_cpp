#include <iostream>
#include <cmath>

#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int main(void)
{
    FAST_IO;
    int n;
    cin >> n;

    long long int len = 1, ret = 0;
    int num = pow(10, len) - pow(10, len-1);
    while (n - num >= 0) {
        ret += len * num;
        n = n - num;
        len++;

        num = pow(10, len) - pow(10, len-1);
    }
    ret += len * n;
    cout << ret;
    return 0;
}