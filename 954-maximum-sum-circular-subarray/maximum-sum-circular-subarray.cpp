class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int currSum = nums[0];
        int maxSum = nums[0];
        int minCurrSum = nums[0];
        int minSum = nums[0];
        int totalSum = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            currSum = max(currSum + nums[i], nums[i]);
            maxSum = max(currSum, maxSum);

            minCurrSum = min(minCurrSum + nums[i], nums[i]);
            minSum = min(minSum, minCurrSum);

            totalSum += nums[i];
        }
        return maxSum < 0 ? maxSum : max(maxSum, totalSum - minSum);
    }
};