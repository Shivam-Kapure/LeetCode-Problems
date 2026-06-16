class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minSize = INT_MAX;
        int left = 0;
        int currSum = 0;

        for(int right = 0; right < nums.size(); right++) {
            currSum += nums[right];

            while(currSum >= target) {
                minSize = min(right - left + 1, minSize);
                currSum -= nums[left];
                left++;
            }

        }
        return minSize == INT_MAX ? 0 : minSize;
    }
};