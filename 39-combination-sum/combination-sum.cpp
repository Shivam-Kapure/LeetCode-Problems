class Solution {
public:
    void helperBT(vector<int>& candidates, vector<int>& combination, vector<vector<int>>& ans,int target, int start) {
        if(target == 0) {
            ans.push_back(combination);
            return;
        }
        for(int i = start; i < candidates.size(); i++) {
            if(target < candidates[i])
                break;
            combination.push_back(candidates[i]);
            helperBT(candidates, combination, ans, target - candidates[i], i);
            combination.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> combination; vector<vector<int>> ans;
        helperBT(candidates, combination, ans, target, 0);
        return ans;
    }
};