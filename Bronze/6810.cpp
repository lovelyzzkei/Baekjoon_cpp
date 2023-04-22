#include <iostream>
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int main(void)
{
    int num;
    int isbn = 9*1 + 7*3 + 8*1 + 0*3 + 9*1 + 2*3 + 1*1 + 4*3 + 1*1 + 8*3;
    cin >> num;
    isbn += num;
    cin >> num;
    isbn += 3*num;
    cin >> num;
    isbn += num;

    cout << "The 1-3-sum is " << isbn;
    return 0;
}

