#include <iostream>
#include <vector>
#include <algorithm>

#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

class Country 
{
public:
    int idx;
    int gold;
    int silver;
    int bronze;
    Country(int i, int g, int s, int b) : idx(i), gold(g), silver(s), bronze(b) {}
    bool sameRank(Country a)
    {
        return (gold == a.gold && silver == a.silver && bronze == a.bronze);
    }
};

int n, k;
vector<Country> medal;

bool compare(Country a, Country b)
{
    if (a.gold == b.gold)
    {
        if (a.silver == b.silver)
        {
            return a.bronze > b.bronze;
        }
        return a.silver > b.silver;
    }
    return a.gold > b.gold;
}

int main(void)
{
    FAST_IO;
    cin >> n >> k;

    int idx, g, c, b;
    for (int i = 0; i < n; i++) {
        cin >> idx >> g >> c >> b;
        medal.push_back(Country(idx, g, c, b));
    }
    sort(medal.begin(), medal.end(), compare);

    int rank = 1;
    for (int i = 0; i < n; i++) {
        if (medal[i].idx == k)
        {
            for (int j = 0; j < i; j++) {
                if (!medal[j].sameRank(medal[i]))
                    rank++;
            }
        }
    }

    cout << rank;

    return 0;
}