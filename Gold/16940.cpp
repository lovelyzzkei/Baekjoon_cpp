#include <iostream>
#include <deque>
#include <vector>
#include <memory.h>

#define N 100001
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int n, ans[N], height[N];
bool visited[N];
deque<int> dq;
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
    for (int i = 0; i < n; i++) {
        cin >> ans[i];
    }

    memset(visited, 0, N*sizeof(bool));

    int h = 0;
    dq.push_back(1);
    visited[1] = true;

    while (!dq.empty()) {
        int size = dq.size();
        for (int l = 0; l < size; l++) {
            int curr = dq.front();
            dq.pop_front();

            height[curr] = h;
            for (int next : graph[curr]) {
                if (!visited[next])
                {
                    visited[next] = true;
                    dq.push_back(next);
                }
            }
        }

        h++;
    }

    bool correct = true;
    for (int i = 0; i < n-1; i++) {
        if (height[ans[i]] > height[ans[i+1]])
        {
            correct = false;
            break;
        }
    }

    if (correct)
        cout << 1;
    else
        cout << 0;

    return 0;
}