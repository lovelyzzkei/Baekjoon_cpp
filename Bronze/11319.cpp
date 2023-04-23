#include <iostream>
#include <string>
#include <utility>
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int n;
string input;
pair<int, int> ans;

void countConsVowel()
{
    ans.first = 0;
    ans.second = 0;
    
    for (int i = 0; i < input.size(); i++) {
        if (input[i] == 'A' || input[i] == 'a' || \
            input[i] == 'E' || input[i] == 'e' || \
            input[i] == 'I' || input[i] == 'i' || \
            input[i] == 'O' || input[i] == 'o' || \
            input[i] == 'U' || input[i] == 'u')
            ans.first++;
        else if (input[i] != ' ')
            ans.second++;
    }
}

int main(void)
{
    FAST_IO;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        getline(cin, input);
        countConsVowel();
        cout << ans.second << " " << ans.first << endl;
    }
}