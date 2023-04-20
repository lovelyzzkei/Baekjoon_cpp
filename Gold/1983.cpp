#include <iostream>

#define MAX 401
#define INF -40001

using namespace std;

int A[MAX], B[MAX];
int cache[MAX][MAX][MAX];
int n, lenA, lenB, blankA = 0, blankB = 0;

void input()
{
    // get input A, B and calculate the number of blank
    int num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        if (num != 0)
            A[i-blankA] = num;
        else   
            blankA++;
    }
    for (int i = 0; i < n; i++) {
        cin >> num;
        if (num != 0)
            B[i-blankB] = num;
        else   
            blankB++;
    }
    lenA = n - blankA;
    lenB = n - blankB;
}

void initCache()
{
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            for (int k = 0; k < MAX; k++)
                cache[i][j][k] = INF;
}


int numberBox(int i, int j, int k)
{
    if (j == lenA || k == lenB) return 0;
    
    int& ret = cache[i][j][k];
    if (ret != INF) return ret;

    ret = A[j]*B[k] + numberBox(i+1, j+1, k+1);
    if (lenA - j < n - i)
        ret = max(ret, numberBox(i+1, j, k+1));
    if (lenB - k < n - i)
        ret = max(ret, numberBox(i+1, j+1, k));

    return ret;
}


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    input();
    initCache();

    cout << numberBox(0, 0, 0);

    return 0;
}