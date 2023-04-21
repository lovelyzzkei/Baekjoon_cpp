#include <iostream>
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int main(void)
{
    FAST_IO;
    int a, b;
    cin >> a >> b;
    cout << b + (b-a);
    return 0;
}