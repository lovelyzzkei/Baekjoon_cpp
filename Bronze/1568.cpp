#include <iostream>
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int main(void)
{
    FAST_IO;
    int n;
    cin >> n;

    int k = 1;
    int second = 0;
    while (n != 0) {
        if (n >= k)
        {
            n -= k;
            second++;
            k++;
        }
        else
        {
            k = 1;
        }
    }

    cout << second;
    
    return 0;
}