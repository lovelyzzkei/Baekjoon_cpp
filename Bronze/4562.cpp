#include <iostream>
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int main(void)
{
    FAST_IO;
    int n, a, b;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        cout << ((a >= b) ? "MMM BRAINS" : "NO BRAINS") << endl; 

    }
    return 0;
}