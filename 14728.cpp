#include <iostream>
#include <cmath>
using namespace std;

int n, t;
int studyTime[101], score[101], maxScore[101][10001];

int getMaxScore(int curr, int remainTime) 
{
    if (curr == n) return 0;
    if (maxScore[curr][remainTime] != -1) return maxScore[curr][remainTime];

    maxScore[curr][remainTime] = getMaxScore(curr+1, remainTime);
    if (studyTime[curr] <= remainTime) {
        maxScore[curr][remainTime] = max(maxScore[curr][remainTime], score[curr] + getMaxScore(curr+1, remainTime - studyTime[curr]));
    } 

    return maxScore[curr][remainTime];
}

int main()
{
    cin >> n >> t;

    for (int i = 0; i < n; i++) {
        cin >> studyTime[i] >> score[i];
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= t; j++) {
            maxScore[i][j] = -1;
        }
    }

    cout << getMaxScore(0, t) << endl;

    return 0;
}