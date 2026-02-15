class Solution {
public:
    void helperBT(vector<int>& candidates, vector<vector<int>>& ans, vector<int>& combination, int target, int start) {
        if(target == 0) {
            ans.push_back(combination);
            return;
        }

        for(int i = start; i < candidates.size(); i++) {
            if(i > start && candidates[i] == candidates[i - 1])
                continue;
            if(target < candidates[i])
                break;
            combination.push_back(candidates[i]);
            helperBT(candidates, ans, combination, target - candidates[i], i + 1);
            combination.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> combination; vector<vector<int>> ans;
        helperBT(candidates, ans, combination, target, 0);
        return ans;
    }
};