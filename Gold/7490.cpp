#include <iostream>
#include <stack>
#include <string>

#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int n, t;
string s;

void makeZero(int num)
{
    s.push_back(num + '0');

    if (num == n)
    {
        int sum = 0, idx = 0;
        char op = '+';
        // cout << s << endl;
        while (idx < (int)s.size()) {
            string curr("");
            if (s[idx] != '+' || s[idx] != '-')
            {
                while (idx < (int)s.size() && s[idx] != '+' && s[idx] != '-') {
                    if (s[idx] != ' ')
                        curr.push_back(s[idx]);
                    idx++;
                }
            }
            // cout << curr << endl;

            if (op == '+') sum += stoi(curr);
            if (op == '-') sum -= stoi(curr);

            if (idx < (int)s.size())
                op = s[idx++];

        }

        if (sum == 0)
            cout << s << endl;
        s.pop_back();
        return;
    }

    s.push_back(' ');
    makeZero(num+1);
    s.pop_back();

    s.push_back('+');
    makeZero(num+1);
    s.pop_back();

    s.push_back('-');
    makeZero(num+1);
    s.pop_back();

    s.pop_back();
}

int main(void)
{
    FAST_IO;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        makeZero(1);
        if (i != t-1)
            cout << endl;
    }

    return 0;
}