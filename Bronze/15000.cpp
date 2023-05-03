#include <iostream>
#include <string>

#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main(void)
{
    FAST_IO;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        s[i] = toupper(s[i]);
    }
    cout << s;
    return 0;
}