#include <iostream>

#define MAX_N 101
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int n, k;
int durability[2*MAX_N+1], belt[2*MAX_N+1], robot[2*MAX_N];

int main(void)
{
    FAST_IO;
    cin >> n >> k;
    for (int i = 1; i <= 2*n; i++) {
        cin >> durability[i];
        belt[i] = i;
    }

    int step = 1;
    int numOfZeroDurability = 0;
    while (1) {

        // first step
        int last = belt[2*n];
        for (int i = 2*n; i >= 1; i--) {
            belt[i] = belt[i-1];

            // pull down
            if (robot[belt[n]] == 1)
                robot[belt[n]] = 0;
        }
        belt[1] = last;



        // second step
        for (int i = n-1; i > 0; i--) {
            if (robot[belt[i]] != 0 && robot[belt[i+1]] == 0 && durability[belt[i+1]] > 0)
            {
                robot[belt[i]] = 0;
                robot[belt[i+1]] = 1;
                durability[belt[i+1]]--;
                if (durability[belt[i+1]] == 0)
                    numOfZeroDurability++;

                // pull down
                if (robot[belt[n]] == 1)
                    robot[belt[n]] = 0;
            }
        }




        // third step
        if (durability[belt[1]] != 0)
        {
            robot[belt[1]] = 1;
            durability[belt[1]]--;
            if (durability[belt[1]] == 0)
                numOfZeroDurability++;
        }

        // fourth step
        if (numOfZeroDurability >= k)
            break;
        
        step++;
    }

    cout << step;
    return 0;
}
