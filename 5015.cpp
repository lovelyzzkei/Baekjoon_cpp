#include <iostream>
#include <string>

using namespace std;

int cache[101][101];
string wildCard;
string pattern;

void initCache()
{
    for (int i = 0; i < 101; i++)
    {
        for (int j = 0; j < 101; j++)
        {
            cache[i][j] = -1;
        }
    }
}

bool matched(int w, int p)
{
    int& ret = cache[w][p];
    if (ret != -1) return ret;
    
    if (w < wildCard.size() && p < pattern.size() && \
            (wildCard[w] == pattern[p]))
    {
        return ret = matched(w+1, p+1);
    }

    if (w == wildCard.size()) return ret = (p == pattern.size());
    if (wildCard[w] == '*')
    {   
        if (matched(w+1, p) || (p < pattern.size() && matched(w, p+1)))
        {
            return ret = 1;
        }
    }
    
    return ret = 0;
}


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int numOfPattern;

    cin >> wildCard;
    cin >> numOfPattern;
    
    for (int i = 0; i < numOfPattern; i++)
    {
        initCache();
        cin >> pattern;
        if (matched(0, 0))
        {
            cout << pattern << endl;
        }
    }

    return 0;
}