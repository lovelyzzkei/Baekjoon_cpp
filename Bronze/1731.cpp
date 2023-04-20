#include <iostream>
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int sequences[51];

int main(void)
{
    FAST_IO;
    int n, num;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> sequences[i];
    }

    int diff = 0;
    if (sequences[1] - sequences[0] == sequences[2] - sequences[1])
    {
        diff = sequences[1] - sequences[0];
        cout << sequences[n-1] + diff;
    }
    else
    {
        diff = sequences[1] / sequences[0];
        cout << sequences[n-1] * diff;
    }
    
    return 0;
}