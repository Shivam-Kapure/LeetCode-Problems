class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0; int fast = 0;
        while(true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast)
                break;
        }
        int entry = 0;
        while(true) {
            slow = nums[slow];
            entry = nums[entry];
            if(slow == entry)
                return entry;
        }
        return 0;
    }
};