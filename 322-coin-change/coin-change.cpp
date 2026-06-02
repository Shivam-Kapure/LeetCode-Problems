class Solution {
public:
    int helper(int idx, vector<int>& coins, int amount, vector<vector<int>>& dp) {
        if (amount == 0)
            return 0;

        if (idx == coins.size())
            return 1e9;

        if (dp[idx][amount] != -1)
            return dp[idx][amount];

        int notTake = helper(idx + 1, coins, amount, dp);

        int take = 1e9;
        if (coins[idx] <= amount) {
            take = 1 + helper(idx, coins, amount - coins[idx], dp);
        }

        return dp[idx][amount] = min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));

        int ans = helper(0, coins, amount, dp);

        return (ans >= 1e9) ? -1 : ans;
    }
};