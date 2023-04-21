#include <iostream>
#include <vector>
#include <algorithm>

#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int n, c;
vector<int> houses;

int main(void)
{
    FAST_IO;
    int num;

    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        cin >> num;
        houses.push_back(num);
    }

    sort(houses.begin(), houses.end());

    int left = 0, right = 1000000001;
    while (left + 1 < right) {
        int mid = (left + right) / 2;
        int x = 0, cnt = 1;
        for (int i = 1; i < n; i++) {
            if (houses[i] - houses[x] >= mid) 
            {
                cnt++;
                x = i;
            }
        }

        if (cnt < c) right = mid;
        else left = mid;
    }

    cout << left;
    return 0;
}
