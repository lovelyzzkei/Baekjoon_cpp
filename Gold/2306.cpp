#include <iostream>
#include <string>

#define MAX 501

using namespace std;

string dna;
int dp[MAX][MAX];

int isKOI(int start, int end)
{
    return (dna[start] == 'a' && dna[end] == 't') \
        || (dna[start] == 'g' && dna[end] == 'c');

}


int getLongestKOI(int start, int end) 
{
    if (end - start == 1) 
    {
        if (isKOI(start, end)) return 2;
        else return 0;
    }

    int& cache = dp[start][end];
    if (cache != -1) return cache;

    cache = 0;
    if (isKOI(start, end)) {
        cache = max(cache, getLongestKOI(start+1, end-1) + 2);
    }
    for (int i = start; i < end; i++) {
        cache = max(cache, getLongestKOI(start, i) + getLongestKOI(i+1, end));
    }

    return cache;
}



int main(void)
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> dna;

    for (int i = 0; i < MAX; i++) {
        fill_n(dp[i], MAX, -1);
    }
    
    int len = (int)dna.length();
    getLongestKOI(0, len-1);

    cout << dp[0][len-1];

    return 0;
}
