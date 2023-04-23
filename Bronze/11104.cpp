#include <iostream>
#include <string>
#include <cmath>
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int n;
string input;

int strToBinary()
{
    int ret = 0;
    for (int i = 0; i < input.size(); i++) {
        if (input[23-i] == '1') ret += pow(2, i);
    }
    return ret;
}

int main(void)
{
    FAST_IO;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> input;
        cout << strToBinary() << endl;
    }
}