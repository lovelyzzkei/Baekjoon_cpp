#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <memory.h>

#define N 101
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int n, chart[N][2];
bool visited[N], cycle[N];
vector<int> result;

int dfs(int curr)
{
    if (cycle[curr])
        return curr;
    cycle[curr] = true;
    int val = chart[curr][1];
    return dfs(val);
}

void makeSet(int start)
{
    visited[start] = true;
    result.push_back(start);
    int curr = chart[start][1];

    while (curr != start) {
        visited[curr] = true;
        result.push_back(curr);
        curr = chart[curr][1];
    }
}


int main(void)
{
    FAST_IO;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        chart[i][0] = i;
        cin >> chart[i][1];
    }

    memset(visited, 0, N*sizeof(bool));

    for (int i = 1; i <= n; i++) {
        memset(cycle, 0, N*sizeof(bool));
        if (!visited[i])
        {
            int start = dfs(i);
            if (!visited[start])
            {
                makeSet(start);
            }

        }
    }

    set<int> s(result.begin(), result.end());
    cout << (int)s.size() << endl;
    for (const int &num : s) {
        cout << num << endl;
    }

    return 0;
}