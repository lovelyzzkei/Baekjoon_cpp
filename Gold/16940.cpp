#include <iostream>
#include <deque>
#include <vector>
#include <memory.h>
#include <algorithm>

#define N 100001
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int n;
bool visited[N];
deque<int> dq, ans;
vector<vector<int>> graph(N);

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
        ans.push_back(num);
    }

    memset(visited, 0, N*sizeof(bool));

    
    if (ans.front() != 1)
    {
        cout << 0;
        return 0;
    }

    visited[ans.front()] = true;
    dq.push_back(ans.front());
    ans.pop_front();

    while (!dq.empty()) {
        int curr = dq.front();
        dq.pop_front();
        
        while (true) {
            int next = ans.front();
            auto iter = find(graph[curr].begin(), graph[curr].end(), next);

            if (iter == graph[curr].end())
                break;

            visited[next] = true;
            ans.pop_front();
            dq.push_back(next);
        }

        for (auto iter = graph[curr].begin(); iter != graph[curr].end(); iter++) {
            if (!visited[*iter])
            {
                cout << 0;
                return 0;
            }
        }

    }
   
    cout << 1;
    return 0;
}