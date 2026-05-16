#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int lo = 0, hi = nums.size() - 1;

        while (lo < hi)
        {

            if (nums[lo] < nums[hi])
                return nums[lo];

            int mid = lo + (hi - lo) / 2;

            if (nums[mid] > nums[mid + 1])
                return nums[mid + 1];

            if (nums[mid] > nums[lo])
                lo = mid + 1;
            else if (nums[mid] < nums[lo])
                hi = mid;
            else
                lo++;
        }

        return nums[lo];
    }
};