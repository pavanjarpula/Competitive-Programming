#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int n;
    int dp[10001];
    vector<int> a;

    int rec(int i)
    {

        if (i >= n - 1)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int ans = 1e9;

        for (int jump = 1; jump <= a[i]; jump++)
        {
            ans = min(ans, 1 + rec(i + jump));
        }

        return dp[i] = ans;
    }

    int jump(vector<int> &nums)
    {
        memset(dp, -1, sizeof(dp));
        a = nums;
        n = nums.size();

        return rec(0);
    }
};