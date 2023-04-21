#include <iostream>
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int main(void)
{
    FAST_IO;
    int n, t = 1;
    while (true) {
        cin >> n;
        if (n == 0)
            break;
        
        int n1 = 3*n, n4 = 0;
        if (n1 % 2 == 0) 
            n4 = n / 2;
        else
            n4 = (n-1) / 2;
        cout << t << ". " << ((n1%2==0)?"even ":"odd ") << n4 << endl;
        t++;
    }
    return 0;
}