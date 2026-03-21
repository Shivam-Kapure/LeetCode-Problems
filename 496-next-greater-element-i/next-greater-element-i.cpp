class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> umap;
        stack<int> st;
        vector<int> ans(nums1.size(), -1);

        for(int n : nums2) {
            auto it = find(nums1.begin(), nums1.end(), n);
            if(it != nums1.end()) {
                int idx = it - nums1.begin();
                umap[n] = idx;
            }
        }
        for(int i = 0; i < nums2.size(); i++) {
            int curr = nums2[i];
            while(!st.empty() && curr > st.top()) {
                int val = st.top();
                st.pop();
                int idx = umap[val];
                ans[idx] = curr;
            }
            auto it = umap.find(curr);
            if(it != umap.end()) {
                st.push(curr);
            }
        }
        return ans;
    }
};