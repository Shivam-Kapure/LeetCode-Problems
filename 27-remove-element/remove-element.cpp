class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for(int n : nums) {
            if(n == val) {
                nums.erase(remove(nums.begin(), nums.end() , n), nums.end());
            }
        }
        int len = nums.size();
        return len;
        
    }
};