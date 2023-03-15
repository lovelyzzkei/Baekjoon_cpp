/*
    Date: 2023/03/15
    Name: 2666-벽장문의 이동
    Category: Dynamic Programming
*/

#include <iostream>

#define MAX 21

using namespace std;

int n, first, second;
int len, order[MAX], dp[MAX][MAX][MAX];

int move(int n, int first, int second) 
{   
    int& cache = dp[n][first][second];
    if (n == len) return 0;
    if (cache != -1) return cache;

    cache = min(abs(order[n]-first) + move(n+1, order[n], second), abs(order[n]-second) + move(n+1, first, order[n]));

    return cache;
}

int main()
{
    cin >> n;
    cin >> first >> second;

    cin >> len;
    for (int i = 0; i < len; i++) {
        cin >> order[i];
    }

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            for (int k = 0; k < MAX; k++) {
                dp[i][j][k] = -1;
            }
        }
    }

    cout << move(0, first, second);

    return 0;
}