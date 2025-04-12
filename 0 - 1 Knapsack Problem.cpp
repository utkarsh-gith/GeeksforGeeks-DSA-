// 2-D DP
// two parameters are changing (index and W)
// so two dimensions one with index size (0 -> n - 1) and
// another with max weight (0 -> W)
// Recursion (TLE)

class Solution
{
public:
    int helper(vector<int> &val, vector<int> &wt, int W, int index)
    {
        if (W == 0 || index == val.size())
        {
            return 0;
        }

        int maxVal = helper(val, wt, W, index + 1);

        if (W >= wt[index])
        {
            maxVal = max(maxVal, val[index] + helper(val, wt, W - wt[index], index + 1));
        }

        return maxVal;
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt)
    {
        // code here
        return helper(val, wt, W, 0);
    }
};

// Recursion + Memorisation

class Solution
{
public:
    int helper(vector<int> &val, vector<int> &wt, int W, int index, vector<vector<int>> &dp)
    {
        if (W == 0 || index == -1)
        {
            return 0;
        }

        if (dp[index][W] != -1)
        {
            return dp[index][W];
        }
        dp[index][W] = helper(val, wt, W, index - 1, dp);

        if (W >= wt[index])
        {
            dp[index][W] = max(dp[index][W], val[index] + helper(val, wt, W - wt[index], index - 1, dp));
        }

        return dp[index][W];
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt)
    {
        // code here
        vector<vector<int>> dp(wt.size(), vector<int>(W + 1, -1));
        return helper(val, wt, W, val.size() - 1, dp);
    }
};

// Tabulation
