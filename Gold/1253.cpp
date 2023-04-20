#include <iostream>
#include <vector>
#include <algorithm>

#define N 2001
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int n;
vector<int> nums;

bool goodNumber(int num, int pos)
{
    int left = 0, right = n-1;
    if (pos == left) left++;
    if (pos == right) right--;

    while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum == num)
        {
            if (left != right && left != pos && right != pos)
                return true;

            if (left == pos)
                left++;
            else 
                right--;
        }
        else if (sum > num)
            right--;
        else
            left++;

    }


    if (nums[left] + nums[right] == num)
    {
        if (left != right && left != pos && right != pos)
            return true;
    }
    return false;
}

int main(void)
{
    FAST_IO;
    cin >> n;
    int input;
    for (int i = 0; i < n; i++) {
        cin >> input;
        nums.push_back(input);
    }


    int ret = 0;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++) {
        if (goodNumber(nums[i], i))
            ret++;    
    }

    cout << ret;
    return 0;
}