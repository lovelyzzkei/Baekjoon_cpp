#include <iostream>
#include <string>

using namespace std;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string name = "최백준";
    for (int i = 0; i < (int)name.length(); i+=2) {
        cout << name.substr(i, 2);
    }
    cout << endl;
    cout << name << endl;

    return 0;
}