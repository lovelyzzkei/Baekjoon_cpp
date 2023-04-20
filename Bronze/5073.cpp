#include <iostream>
#include <vector>
#include <algorithm>

#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main(void)
{
    FAST_IO;
    int a, b, c;
    vector<int> side(3);
    while (true) {
        cin >> side[0] >> side[1] >> side[2];
        sort(side.begin(), side.end());

        a = side[0]; b = side[1]; c = side[2];
        if (a == 0 && b == 0 && c == 0)
            break;

        if (c >= a + b)
            cout << "Invalid" << endl;
        else if (a == b && b == c)
            cout << "Equilateral" << endl;
        else if (a == b || b == c || a == c)
            cout << "Isosceles" << endl;
        else
            cout << "Scalene" << endl;
    }

    return 0;
}