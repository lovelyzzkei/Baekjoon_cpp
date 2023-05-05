#include <iostream>
#include <stack>
#include <vector>
#include <memory.h>
#include <algorithm>

#define N 100001
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int n, order[N], given[N], path[N], l=0;
bool visited[N];
vector<int> graph[N];

bool comp(int a, int b)
{
    return order[a] < order[b];
}

void dfs(int curr)
{
    visited[curr] = true;
    path[l++] = curr;
    for (int next : graph[curr]) {
        if (!visited[next])
            dfs(next);
    }
}

int main(void)
{
    FAST_IO;
    cin >> n;

    int a, b;
    for (int i = 0; i < n-1; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        given[i] = num;
        order[num] = i;
    }   
    
    memset(visited, 0, N*sizeof(bool));
    for (int i = 1; i <= n; i++)
        sort(graph[i].begin(), graph[i].end(), comp);


    dfs(1);
    for (int i = 0; i < n; i++) {
        if (given[i] != path[i])
        {
            cout << 0;
            return 0;
        }
    }

    cout << 1;
    return 0;
}