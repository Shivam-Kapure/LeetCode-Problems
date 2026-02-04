class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        if(nums.size() < 4)
            return false;
        
        int i = 0;

        while(i + 1 < nums.size() && nums[i + 1] > nums[i])
            i++;
        if(i == 0 || i == nums.size() - 1)
            return false;
        int j = i;

        while(j + 1 < nums.size() && nums[j + 1] < nums[j])
            j++;
        if(j == i || j == nums.size() - 1) 
            return false;
        int k = j;

        while(k + 1 < nums.size()) {
            if(nums[k + 1] <= nums[k])
                return false;
            k++;
        }      
        return k == nums.size() - 1;
    }
};