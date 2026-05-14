#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isGood(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        int m = nums.size();

        for (int i = 0; i < m - 1; i++)
        {
            if (nums[i] != i + 1)
                return false;
        }

        return nums[m - 1] == m - 1;
    }
};