#include <iostream>
#include <string>

#define MAX 51
#define INF 51

using namespace std;

string origin;
int cache[MAX][MAX];

void initCache()
{
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            cache[i][j] = INF;
}

int keyboard(int cursor, int enter, string& s, char prev)
{
    if (enter == s.size()) return 0;

    int& ret = cache[cursor][enter];
    if (ret != INF) return ret;

    for (int i = 0; i < s.size(); i++) {
        char curr = s[i];
        if (curr != ' ' && curr >= prev)
        {   
            string c;
            c += curr;

            s.replace(i, 1, " ");
            ret = min(ret, abs(cursor-i) + 1 + keyboard(i, enter+1, s, curr));
            s.replace(i, 1, c);
        }
    }

    return ret;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> origin;
    s = origin;
    initCache();

    cout << keyboard(0, 0, s, 'a');

    cout << endl;
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < 4; j++) {
            cout << cache[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}