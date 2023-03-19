/*
    Date: 2023/03/14 
    Name: 27210-신을 모시는 사당
    Category: Dynamic Programming
    Key: Double maximum subarray(kadene's algorithm)
*/

#include <iostream>

#define MAX 100001

using namespace std;

int main()
{
    int n;
    int arr[MAX], maxEndingAt[MAX], minEndingAt[MAX];

    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    // left: -1 right: 1
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (num == 1) {
            arr[i] = -1;
        }
        else {
            arr[i] = 1;
        }
    }

    maxEndingAt[0] = max(arr[0], 0);
    minEndingAt[0] = min(arr[0], 0);

    int maxLeft = maxEndingAt[0];
    int minRight = minEndingAt[0];

    for (int i = 1; i < n; i++) {
        maxEndingAt[i] = max(maxEndingAt[i-1] + arr[i], 0);
        if (maxEndingAt[i] > maxLeft) {
            maxLeft = maxEndingAt[i];
        }

        minEndingAt[i] = min(minEndingAt[i-1] + arr[i], 0);
        if (minEndingAt[i] < minRight) {
            minRight = minEndingAt[i];
        }
    }

    cout << max(maxLeft, abs(minRight));

    return 0;
}