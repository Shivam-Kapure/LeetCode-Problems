class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> list(n, 1);

        for(int i = n - 1; i >= 0; i--) {
            for(int j = i + 1; j < n; j++) {
                if(nums[i] < nums[j])
                    list[i] = max(list[i], 1 + list[j]);
            }
        }
        return *max_element(list.begin(), list.end());
    }
};