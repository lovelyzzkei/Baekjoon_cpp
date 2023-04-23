#include <iostream>
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int main(void)
{
    FAST_IO;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << "Hello World, Judge " << i << "!" << endl;
    }

    return 0;
}