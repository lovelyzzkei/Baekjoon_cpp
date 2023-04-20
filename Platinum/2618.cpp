#include <iostream>
#include <vector>
#include <utility>

#define MAX 1001
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int n, w;
int numOfPolice[MAX][MAX];
int cache[MAX][MAX];
vector<pair<int, int>> cases;


void initCache()
{
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            cache[i][j] = -1;
        }
    }
}


int dist(int src, int dest, int num)
{
    int srcY = cases[src].first;
    int srcX = cases[src].second;
    int destY = cases[dest].first;
    int destX = cases[dest].second;

    if (src == 0) 
    {
        if (num == 1) 
        {
            srcY = 1;
            srcX = 1;
        }
        else
        {
            srcY = n;
            srcX = n;
        }
    }
    return abs(srcY - destY) + abs(srcX - destX);
}


void backtrace()
{
    int first = 0, second = 0, numCase = 0;

    while (numCase != w)
    {
        int cop = numOfPolice[first][second];
        cout << cop << endl;

        if (cop == 1)
            first = numCase + 1;
        else
            second = numCase + 1;
        numCase++;
    } 

}


int police(int first, int second)
{
    if (first == w || second == w) return 0;

    int& ret = cache[first][second];
    if (ret != -1) return ret;

    int curr = max(first, second) + 1;
    int firstTake = police(curr, second) + dist(first, curr, 1);
    int secondTake = police(first, curr) + dist(second, curr, 2);

    numOfPolice[first][second] = (firstTake <= secondTake) ? 1 : 2;

    return ret = min(firstTake, secondTake);
}


int main(void)
{
    FAST_IO;
    cin >> n >> w;

    int y, x;
    cases.push_back(make_pair(-1, -1));
    for (int i = 0; i < w; i++) {
        cin >> y >> x;
        cases.push_back(make_pair(y, x));
    }

    initCache();
    cout << police(0, 0) << endl;
    backtrace();


    return 0;
}
