class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int, int> count;
        vector<vector <int>> freq(nums.size() + 1);
        
        for(int n : nums) {
            count[n] = 1 + count[n];
        }
        for(auto const& value : count) {
            freq[value.second].push_back(value.first);
        }
        vector <int> result;
        for(int i = freq.size() - 1; i > 0; --i) {
            for(int n : freq[i]) {
                result.push_back(n);
                if(result.size() == k) {
                    return result;
                }
            }
        }
        return result;
    }
};