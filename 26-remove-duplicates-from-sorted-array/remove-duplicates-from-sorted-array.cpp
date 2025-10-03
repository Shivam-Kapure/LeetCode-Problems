class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for(auto e : nums) {
            if(i == 0 || nums[i-1] != e) {
                nums[i] = e;
                i++;
            }
        }
        return i;
        // int i = 0;
        // for(int j = 1; j < nums.size(); j++) {
        //     if(nums[j] != nums[i]) {
        //         i++;
        //         nums[i] = nums[j];
        //     } 
        // }
        // return i + 1;
    }
};