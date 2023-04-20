#include <iostream>
#include <string>
#include <algorithm>

#define MAX_N 1000001
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); 

using namespace std;

int n;
string src, dst;

int pushSwitch(string &str)
{
    int num = 0;
    for (int i = 1; i < n; i++) {
        if (str[i-1] != dst[i-1])
        {
            num++;
            str.replace(i-1, 1, ((str[i-1] == '1') ? "0" : "1"));
            str.replace(i, 1, ((str[i] == '1') ? "0" : "1"));

            if (i != n-1)
                str.replace(i+1, 1, ((str[i+1] == '1') ? "0" : "1"));
        }
    }


    if (!str.compare(dst))
        return num;

    else   
        return MAX_N;
}

int main(void)
{
    FAST_IO;
    cin >> n;
    cin >> src >> dst;

    string pushFirst(src);
    if (pushFirst[0] == '1') pushFirst.replace(0, 1, "0");
    else pushFirst.replace(0, 1, "1");

    if (pushFirst[1] == '1') pushFirst.replace(1, 1, "0");
    else pushFirst.replace(1, 1, "1");

    int num1 = pushSwitch(src);
    int num2 = pushSwitch(pushFirst) + 1;

    if (num1 >= MAX_N && num2 >= MAX_N)
        cout << -1;
    else
        cout << min(num1, num2);

    return 0;
}