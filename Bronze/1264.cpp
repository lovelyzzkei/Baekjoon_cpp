#include <iostream>
#include <string>

#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int main(void)
{
    FAST_IO;
    string input;
    while (true) {
        getline(cin, input);
        if (!input.compare("#"))
            break;

        int numOfVowel = 0;
        for (int i = 0; i < (int)input.size(); i++) {
            if (input[i] == 'a' || input[i] == 'A' || \
                input[i] == 'e' || input[i] == 'E' || \
                input[i] == 'i' || input[i] == 'I' || \
                input[i] == 'o' || input[i] == 'O' || \
                input[i] == 'u' || input[i] == 'U')
                numOfVowel++;
        }

        cout << numOfVowel << endl;
    }
    return 0;
}