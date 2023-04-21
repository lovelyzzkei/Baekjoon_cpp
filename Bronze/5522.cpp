#include <iostream>
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int main(void)
{
    FAST_IO;
    int num, sum = 0;
    for (int i = 0; i < 5; i++) {
        cin >> num;
        sum += num; 
    }
    cout << sum;
    return 0;
}