#include <iostream>
#include <memory.h>

#define N 100001
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int n, seq[N];
bool visited[N];

int main(void)
{
    FAST_IO;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> seq[i];
    }
    
    memset(visited, 0, N*sizeof(bool));

    int left = 0, right;
    long long int cnt = 1;
    visited[seq[left]] = true;
    
    for (right = 1; right < n; right++) {
        while (visited[seq[right]]) {
            visited[seq[left]] = false;
            left++;
            cnt += (right - left);
        }

        visited[seq[right]] = true;
        cnt++;
    }

    while (left < right) {
        left++;
        cnt += (right - left);
    }

    cout << cnt;
    return 0;
}