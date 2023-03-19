#include <iostream>
#include <string>

#define MAX 501

string dna;
int dp[MAX][MAX];

using namespace std;

int isSmallestKOI(int start, int end)
{
    return (dna[start] == 'a' && dna[end] == 't') \
        || (dna[start] == 'g' && dna[end] == 'c');

}


int getLongestKOI(int start, int end) 
{
    if (end - start == 1) 
    {
        if (isSmallestKOI(start, end)) return 2;
        else return 0;
    }

    int len = (int)dna.length();
    int& cache = dp[start][end];
    if (cache != -1) return cache;

    cache = 0;
    for (int i = 0; i < len; i++) {
        
    }
}



int main(void)
{
    cin >> dna;

    for (int i = 0; i < MAX; i++) {
        fill_n(dp[i], MAX, -1);
    }
    
    int len = (int)dna.length();
    getLongestKOI(0, len-1);

    for (int i = 0; i <= dna.length(); i++) {
        for (int j = 0; j <= dna.length(); j++) {
            cout << dp[i][j] << " ";
        }
    }
    cout << endl;

    return 0;
}
