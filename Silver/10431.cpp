#include <iostream>

#define N 20
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int t, students[N];

int main(void)
{
    FAST_IO;
    cin >> t;

    int testcaseNum;
    for (int _ = 0; _ < t; _++) {
        cin >> testcaseNum;

        int sum = 0;
        for (int i = 0; i < N; i++) {
            cin >> students[i];

            if (i == 0) 
                continue;
            
            for (int j = 0; j < i; j++) {
                if (students[j] > students[i]) 
                {
                    int target = students[i];

                    // 뒤로 물러서기
                    for (int k = i; k > j; k--) {
                        students[k] = students[k-1];
                        sum++;
                    }
                    students[j] = target;
                    break;
                }
            }
        }
        cout << testcaseNum << " " << sum << endl;
    }

    return 0;
}