#include <iostream>
#include <vector>
#include <memory.h>

#define N 2001
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int n, m;
bool isFinished = false, visited[N];
vector<vector<int>> relation;

int dfs(int curr)
{
    if (isFinished)
        return 0;
        
    int ret = 0;
    bool isLast = true;
    for (int next : relation[curr]) {
        if (!visited[next])
        {
            isLast = false;
            visited[next] = true;
            ret = max(ret, dfs(next) + 1);
            visited[next] = false;
        }
    }
    
    if (ret >= 4) 
        isFinished = true;

    if (isLast)
        return 0;
        
    if (isFinished)
        return ret;

    return ret;
}

int main(void)
{
    FAST_IO;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        vector<int> v;
        relation.push_back(v);
    }

    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        relation[a].push_back(b);
        relation[b].push_back(a);
    }



    int depth = 0;
    for (int i = 0; i < n; i++) {
        memset(visited, 0, n*sizeof(bool));    
        visited[i] = true;
        depth = max(depth, dfs(i));
    }

    if (isFinished) cout << 1;
    else cout << 0;

    return 0;
}