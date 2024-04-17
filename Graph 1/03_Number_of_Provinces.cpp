#include <bits/stdc++.h>
using namespace std;

// lc547
class Solution
{
public:
    void dfs(vector<vector<int>> &isConnected, int i, vector<int> &visited)
    {
        int n = isConnected.size();
        if (visited[i] == 1)
            return; // checking if already visited then return

        visited[i] = 1; // marking visited
        for (int j = 0; j < n; j++)
        {
            // calling to all cities connected to it through recursion
            if (isConnected[i][j] == 1)
                dfs(isConnected, j, visited);
        }
    }

    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        vector<int> visited(n, 0);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (visited[i] == 0)
            { // calling only if not visited
                ans++;
                dfs(isConnected, i, visited);
            }
        }
        return ans;
    }
};