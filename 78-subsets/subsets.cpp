class Solution {
public:
    void printSubsets(vector<int>& nums, vector<vector<int>>& ans, vector<int>& subset, int level) {
        if(level == nums.size()) {
            ans.push_back(subset);
            return;
        }
        subset.push_back(nums[level]);
        printSubsets(nums, ans, subset, level + 1);
        subset.pop_back();
        printSubsets(nums, ans, subset, level + 1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        int level = 0;
        vector<vector<int>> ans;
        printSubsets(nums, ans, subset, level);
        return ans;
    }
};