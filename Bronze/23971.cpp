#include <iostream>

#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int main(void)
{
    FAST_IO;
    int h, w, n, m;
    cin >> h >> w >> n >> m;

    int row = h / (n + 1);
    int col = w / (m + 1);    
    if (h % (n+1) != 0) row++;
    if (w % (m+1) != 0) col++;

    cout << row*col;
    return 0;
}
