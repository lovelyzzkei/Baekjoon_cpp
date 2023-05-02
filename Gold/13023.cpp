#include <iostream>
#include <vector>
#include <memory.h>

#define N 2001
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, cache[N];
bool visited[N];
vector<vector<int>> relation;

void init() 
{
    memset(visited, 0, n*sizeof(bool));
    for (int i = 0; i < n; i++) {
        cache[i] = -1;
    }
}

int dfs(int prev, int curr)
{
    int &ret = cache[curr];
    if (ret != -1)
        return ret;

    ret = 0;
    bool isLast = true;
    for (int next : relation[curr]) {
        if (!visited[next] || (visited[next] && prev != next))
        {
            isLast = false;
            visited[next] = true;
            ret = max(ret, dfs(curr, next) + 1);
        }
    }

    if (isLast)
        return 0;

    return ret;
}


int main(void)
{
    FAST_IO;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        vector<int> v;
        relation.push_back(v);
        cache[i] = -1;
    }

    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        relation[a].push_back(b);
        relation[b].push_back(a);
    }


    int depth = 0;
    for (int i = 0; i < n; i++) {
        init();
        visited[i] = true;
        depth = max(depth, dfs(-1, i));
    }

    if (depth >= 4) cout << 1;
    else cout << 0;

    return 0;
}