class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        if(nums[left] <= nums[right]) {
            return nums[left];
        }

        while(left < right) {
            int mid = left + (right - left)/2;
            if(nums[mid] > nums[right]) {
                left = mid + 1; //yaha pe we have excluded mid because ceratin case hai jaise ki [2,1] type ka vector
            }
            else {
                right = mid; //because mid can also be min element
            } 
        }
        return nums[left];
    }
};