class Solution {
public:
    set<vector<int>> s;
    void helperBT(vector<int>& candidates, vector<vector<int>>& ans, vector<int>& combination, int level, int target) {
        if(level == candidates.size() || target < 0)
            return;
        if(target == 0) {
            if(s.find(combination) == s.end()) {
                ans.push_back(combination);
                s.insert(combination);
                return;
            }
        }
        combination.push_back(candidates[level]);
        helperBT(candidates, ans, combination, level + 1, target - candidates[level]);
        helperBT(candidates, ans, combination, level, target - candidates[level]);
        combination.pop_back();
        helperBT(candidates, ans, combination, level + 1, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> combination; vector<vector<int>> ans;
        helperBT(candidates, ans, combination, 0, target);
        return ans;
    }
};