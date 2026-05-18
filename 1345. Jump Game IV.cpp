#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minJumps(vector<int> &arr)
    {
        int n = arr.size();
        if (n == 1)
            return 0;

        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++)
            mp[arr[i]].push_back(i);

        queue<int> q;
        vector<int> vis(n, 0);

        q.push(0);
        vis[0] = 1;

        int steps = 0;

        while (!q.empty())
        {
            int sz = q.size();

            while (sz--)
            {
                int cur = q.front();
                q.pop();

                if (cur == n - 1)
                    return steps;

                // i+1
                if (cur + 1 < n && !vis[cur + 1])
                {
                    vis[cur + 1] = 1;
                    q.push(cur + 1);
                }

                // i-1
                if (cur - 1 >= 0 && !vis[cur - 1])
                {
                    vis[cur - 1] = 1;
                    q.push(cur - 1);
                }
                for (int nxt : mp[arr[cur]])
                {
                    if (!vis[nxt])
                    {
                        vis[nxt] = 1;
                        q.push(nxt);
                    }
                }
                mp[arr[cur]].clear();
            }

            steps++;
        }

        return -1;
    }
};