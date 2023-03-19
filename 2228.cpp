/*
    Date: 2023/03/15
    Name: 2228 - 구간 나누기
    Category: Dynamic Programming
    Key: prefix Sum
    Error: Time Limit Exceeded? Why..
*/

#include <iostream>

#define MAX 102
#define MIN_INT -1987654321 // ?

using namespace std;

int n, m;
int arr[MAX], pSum[MAX], dp[MAX][MAX/2];

int divideInterval(int start, int numOfIntervals)
{
    if (numOfIntervals == 0) return 0;
    if (start >= n && numOfIntervals != 0) return MIN_INT;
    if (dp[start][numOfIntervals] != MIN_INT) return dp[start][numOfIntervals];

    dp[start][numOfIntervals] = -1000000007; // ?
    dp[start][numOfIntervals] = max(dp[start][numOfIntervals], divideInterval(start+1, numOfIntervals));
    for (int i = start; i < n; i++) {
        int sum_start_i = pSum[i + 1] - pSum[start];
        dp[start][numOfIntervals] = max(dp[start][numOfIntervals], sum_start_i + divideInterval(i+2, numOfIntervals-1)); 
    }

    return dp[start][numOfIntervals];
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Calculate prefix sum
    pSum[0] = 0;
    for (int i = 1; i <= n; i++) {
        pSum[i] = pSum[i-1] + arr[i-1];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= m; j++) {
            dp[i][j] = MIN_INT;
        }
    }
    

    cout << divideInterval(0, m);

    return 0;
}