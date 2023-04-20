#include <iostream>
#include <set>
#include <deque>
#include <cmath>
#include <memory.h>

#define N 1000001
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int n, k, p, x;
int led[10] = {0b1110111, 0b0010010, 0b1011101, 0b1011011, 0b0111010, \
                0b1101011, 0b1101111, 0b1010010, 0b1111111, 0b1111011};
bool visited[N];    


int kthNumber(int curr, int k)
{
    return (int)(curr / (int)pow(10, k-1)) % 10;
}

int switching(int curr, int k, int target, int changed)
{
    int ret = curr;
    ret -= target*pow(10, k-1);
    ret += changed*pow(10, k-1);
    return ret;
}

int getNumSwitching(int src, int dst)
{
    int num = 0;
    int tmp = led[src] ^ led[dst];
    while (tmp != 0) {
        if (tmp % 2 == 1) num++;
        tmp = tmp >> 1;
    }

    return num;
}

int main(void)
{
    FAST_IO;
    cin >> n >> k >> p >> x;

    memset(visited, 0, N*sizeof(bool));

    set<int> s;
    deque<pair<int, int>> dq;
    dq.push_back(make_pair(x, p));

    while (k > 0 && !dq.empty()) {
        int size = dq.size();
        for (int _ = 0; _ < size; _++) {
            pair<int, int> front = dq.front();
            dq.pop_front();

            int curr = front.first;
            int remainSwitch = front.second;
            int target = kthNumber(curr, k);

            visited[curr] = false;


            for (int i = 0; i <= 9; i++) {
                int next = switching(curr, k, target, i);
                int numSwitch = getNumSwitching(target, i);

                if (!visited[next] && numSwitch <= remainSwitch)
                {
                    if (next != x && (1 <= next && next <= n))
                        s.insert(next);

                    visited[next] = true;
                    dq.push_back(make_pair(next, remainSwitch - numSwitch));
                }
            }
        }
        k--;
    }

    cout << (int)s.size();
    return 0;
}