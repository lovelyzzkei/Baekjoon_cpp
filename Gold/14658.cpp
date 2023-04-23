#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

#define N 500001
#define M 500001
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, l, k;
vector<pair<int, int>> stars;

int Trem(int s1, int s2)
{
    int x = stars[s1].first;
    int y = stars[s2].second;
    int cnt = 0;
    for (int i = 0; i < k; i++) {
        int nx = stars[i].first;
        int ny = stars[i].second;
        if (x <= nx && nx <= x+l && y <= ny && ny <= y+l)
            cnt++;
    }
    return cnt;
}

int main(void)
{
    FAST_IO;
    cin >> n >> m >> l >> k;

    int x, y;
    for (int i = 0; i < k; i++) {
        cin >> x >> y;
        stars.push_back(make_pair(x, y));
    }

    sort(stars.begin(), stars.end());

    int maxBounceOff = 1;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            maxBounceOff = max(maxBounceOff, Trem(i, j));
        }
    }
    
    cout << k - maxBounceOff;
    return 0;
}