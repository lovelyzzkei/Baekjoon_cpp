#include <iostream>
#include <deque>
#include <cmath>
#include <memory.h>

#define N 10001
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int t;
bool visited[N], prime[N];

void aristotle()
{
    for (int i = 0; i < N; i++) 
        prime[i] = true;

    for (int i = 2; i <= (int)sqrt(N); i++) {
        for (int j = i + i; j < N; j+=i) {
            prime[j] = false;
        }
    }
}

int changeOneBit(int curr, int digit, int num)
{
    int d = digit, tmp = curr;
    while (d != 0) {
        tmp /= 10;
        d--;
    }

    int target = tmp % 10;
    curr -= target * pow(10, digit);
    curr += num * pow(10, digit);
    return curr;
}

int main(void)
{
    FAST_IO;
    cin >> t;
    aristotle();

    int a, b;
    for (int _t = 0; _t < t; _t++) {
        cin >> a >> b;

        memset(visited, 0, N*sizeof(bool));
        deque<int> dq;
        dq.push_back(a);
        visited[a] = true;
        
        int cnt = 0;
        bool success = false;
        while (!dq.empty()) {
            int size = dq.size();
            for (int _ = 0; _ < size; _++) {
                int curr = dq.front();
                dq.pop_front();

                if (curr == b)
                {
                    success = true;
                    break;
                }

                for (int i = 0; i < 4; i++) {
                    for (int j = 0; j <= 9; j++) {
                        if (i == 3 && j == 0)
                            continue;

                        int next = changeOneBit(curr, i, j);
                        if (!visited[next] && prime[next])
                        {
                            visited[next] = true;
                            dq.push_back(next);
                        }
                    }
                }
            }
            
            if (success)
                break;

            cnt++;
        }

        if (success)
            cout << cnt << endl;
        else
            cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}