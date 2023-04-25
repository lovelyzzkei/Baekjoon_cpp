#include <iostream>
#include <string>

#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int main(void)
{
    FAST_IO;
    string name;
    int t, score;

    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> name >> score;

        cout << name << " ";
        if (score >= 97) 
            cout << "A+";
        else if (score >= 90) 
            cout << "A";
        else if (score >= 87) 
            cout << "B+";
        else if (score >= 80) 
            cout << "B";
        else if (score >= 77) 
            cout << "C+";  
        else if (score >= 70) 
            cout << "C";
        else if (score >= 67) 
            cout << "D+";
        else if (score >= 60) 
            cout << "D";
        else 
            cout << "F";

        if (i != t-1)
            cout << endl;
    }

    return 0;
}