#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int main(void)
{
    FAST_IO;
    string input;
    vector<int> frequency(26);

    while (getline(cin, input)) {
        for (int i = 0; i < (int)input.size(); i++) {
            if (input[i] != ' ')
                frequency[input[i] - 'a']++;
        }
    }

    int maxFreq = *max_element(frequency.begin(), frequency.end());

    for (int i = 0; i < 26; i++) {
        if (frequency[i] == maxFreq)
            cout << (char)(i + 'a');
    }
    return 0;
}