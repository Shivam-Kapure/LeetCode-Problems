class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        unordered_map <int, int> umap;
        for(int i = 0; i < arr.size(); i++) {
            int first = arr[i];
            int second = target - first;
            if(umap.find(second) != umap.end()) {
                return {umap[second], i};
            }
            umap.insert({first, i});
        }
        return {};
    }
};