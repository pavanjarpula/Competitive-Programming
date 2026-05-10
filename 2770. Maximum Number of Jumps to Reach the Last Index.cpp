#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int n, t;
    vector<int> num;
    vector<int> dp;

    int rec(int level)
    {
        if (level == n - 1)
        {
            return 0;
        }
        if (dp[level] != -1)
        {
            return dp[level];
        }
        int ans = -1e9;
        for (int i = level + 1; i < n; i++)
        {
            if (abs(num[i] - num[level]) <= t)
            {
                int nxt = rec(i);
                if (nxt != -1e9)
                {
                    ans = max(ans, 1 + nxt);
                }
            }
        }
        return dp[level] = ans;
    }

    int maximumJumps(vector<int> &nums, int target)
    {
        num = nums;
        t = target;
        n = nums.size();
        dp.assign(n, -1);
        int ans = rec(0);
        if (ans < 0)
            return -1;
        return ans;
    }
};