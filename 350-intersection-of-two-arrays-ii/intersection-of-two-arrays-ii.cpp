class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> umap;
        vector<int> ans;
        for(int n1 : nums1) {
            umap[n1]++;
        }
        for(int n2 : nums2) {
            if(umap[n2] > 0)
                ans.push_back(n2);
            umap[n2]--;
        }
        return ans;
    }
};