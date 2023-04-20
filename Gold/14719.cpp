#include <iostream>

#define MAX_W 501
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int h, w;
int height[MAX_W];

int square(int w1, int w2)
{
    if (w2 - w1 == 1) return 0;

    int side = min(height[w1], height[w2]);
    int sumHeight = 2*side;
    for (int i = w1 + 1; i <= w2 - 1; i++) {
        if (height[i] >= side)
            sumHeight += side;
        else
            sumHeight += height[i];
    }

    return side * (w2 - w1 + 1) - sumHeight;
}

int main(void)
{
    FAST_IO;
    cin >> h >> w;
    for (int i = 0; i < w; i++) 
        cin >> height[i];

    int longIdx = 0;
    int maxBlock = -1, maxIdx = -1;
    for (int i = 0; i < w; i++) {
        if (height[i] > maxBlock)
        {
            maxBlock = height[i];
            maxIdx = i;
        }
    }

    int sum = 0;
    while (longIdx < maxIdx) {
        int idx = longIdx + 1;
        while (idx < maxIdx && height[idx] < height[longIdx])
            idx++;
        
        sum += square(longIdx, idx);

        longIdx = idx;
    }

    int shortIdx = w-1;
    while (shortIdx > maxIdx) {
        int idx = shortIdx - 1;
        while (idx > maxIdx && height[idx] < height[shortIdx])
            idx--;
    
        sum += square(idx, shortIdx);

        shortIdx = idx;
    }

    cout << sum;
    return 0;
}