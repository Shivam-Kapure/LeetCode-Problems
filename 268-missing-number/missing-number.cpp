class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = (n*n + n)/2;
        int g_sum = 0;
        for(int n : nums)
            g_sum += n;
        
        int ans = sum - g_sum;
        return ans;

    }
};