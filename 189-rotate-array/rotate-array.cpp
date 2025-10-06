class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(k == 0 || nums.size() == 0) {
            return;
        }
        k = k % nums.size();
        // int right = nums.size() - 1;
        // int left = 0;
        // while(left < right) {
        //     int a = nums[left];
        //     nums[left] = nums[right];
        //     nums[right] = a;
        //     left++; right--;
        // }
        reverse(nums.begin(), nums.end());

        // int left1 = 0; int right1 = k - 1;
        // while(left1 < right1) {
        //     int b = nums[left1];
        //     nums[left1] = nums[right1];
        //     nums[right1] = b;
        //     left1++; right1--;
        // }
        reverse(nums.begin(), nums.begin() + k);

        // int left2 = k; int right2 = nums.size() - 1;
        // while(left2 < right2) {
        //     int c = nums[left2];
        //     nums[left2] = nums[right2];
        //     nums[right2] = c;
        //     left2++; right2--;
        // }
        reverse(nums.begin() + k, nums.end());
              
    }
};