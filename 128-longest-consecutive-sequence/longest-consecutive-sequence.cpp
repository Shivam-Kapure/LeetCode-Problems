class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) {
            return 0;
        }
        int max_len = 0;
        unordered_set<int> umap;
        for(int num : nums) {
            if(umap.count(num)) {
                continue;
            }
            umap.insert(num);
        }
        for(int x : umap) {
            if(umap.find(x-1) == umap.end()) {
                int start = x;
                int curr_len = 1;
                int next = x + 1;
                while(umap.find(next) != umap.end()) {
                    curr_len++;
                    next++;
                }
                max_len = max(max_len, curr_len);
            }
        }
        return max_len;
    }
};