class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int first_min = INT_MAX; int sec_min = INT_MAX;
        int a = nums[0];
        nums.erase(nums.begin());
        for(int num : nums) {
            if(num < first_min) {
                sec_min = first_min;
                first_min = num;
            }
            else if(num < sec_min)
                sec_min = num;
        }

        return (a + first_min + sec_min);
    }
};