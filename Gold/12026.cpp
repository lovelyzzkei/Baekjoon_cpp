#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <cmath>

using namespace std;

int blocks[1001];
int minEnergyAt[1001];

int jump(int curr, int n) {
    if (curr == n-1) return 0;
    if (minEnergyAt[curr] != -1) return minEnergyAt[curr];

    minEnergyAt[curr] = 100000001;
    for (int i = curr + 1; i < n; i++) {
        if (blocks[i] == (blocks[curr] + 1) % 3) {
            minEnergyAt[curr] = min(minEnergyAt[curr], jump(i, n) + (int)pow(i-curr, 2));
        }
    }    
    return minEnergyAt[curr];
}

int main () {
    int n;
    string str;

    cin.sync_with_stdio(false);
    cin >> n;
    cin >> str;

    for (int i = 0; i < n; i++) {
        if (str[i] == 'B') {
            blocks[i] = 0;
        } else if (str[i] == 'O') {
            blocks[i] = 1;
        } else {
            blocks[i] = 2;
        }
    }

    for (int i = 0; i < n; i++) {
        minEnergyAt[i] = -1;
    }

    int minEnergy = jump(0, n);
    if (minEnergy != 100000001) {
        cout << minEnergy << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}