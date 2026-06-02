class Solution {
public:
    int helper(int idx, vector<int>& nums, vector<int>& dp) {
        if(idx >= nums.size()) return 0;
        if(dp[idx] != -1) return dp[idx];
        int take = nums[idx] + helper(idx + 2, nums, dp);
        int no = 0 + helper(idx + 1, nums, dp);

        return dp[idx] = max(take, no);
    }

    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return helper(0, nums, dp);
    }
};