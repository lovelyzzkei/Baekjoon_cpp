#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>
#include <unordered_map>

#define N 501
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int order[][3] = {{0, 1, 2}, {0, 2, 1}, {1, 2, 0}};
bool success = false;
deque<vector<int>> dq;
unordered_map<string, bool> visited;

bool isEqual(int a, int b, int c)
{
    return (a == b && b == c && c == a);
}

int main(void)
{
    FAST_IO;
    int a, b, c;
    cin >> a >> b >> c;

    vector<int> start;
    start.push_back(a);
    start.push_back(b);
    start.push_back(c);
    sort(start.begin(), start.end());
    string s;
    for (int n: start)
        s += (to_string(n)+" ");

    dq.push_back(start);
    visited[s] = true;


    while (!dq.empty()) {
        vector<int> curr = dq.front();
        int ca = curr[0];
        int cb = curr[1];
        int cc = curr[2];
        dq.pop_front();

        if (isEqual(ca, cb, cc))
        {
            success = true;
            break;
        }

        for (int i = 0; i < 3; i++) {
            vector<int> next;
            next.push_back(curr[order[i][0]]+curr[order[i][0]]);
            next.push_back(curr[order[i][1]]-curr[order[i][0]]);
            next.push_back(curr[order[i][2]]);
            sort(next.begin(), next.end());

            string str;
            for (int n: next)
                str += (to_string(n)+" ");

            if (visited.find(str) == visited.end())
            {
                visited[str] = true;
                dq.push_back(next);
            }
        }

    }

    if (success)
        cout << 1;
    else
        cout << 0;
    
    return 0;
}