class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        if(nums.size() == 0)
            return {};
        stack<int> st;
        vector<int> ans(nums.size(), -1);

        auto it = max_element(nums.begin(), nums.end());
        int maxIndex = distance(nums.begin(), it);

        for(int i = maxIndex; i >= 0; i--) {
            while(!st.empty() && nums[i] >= st.top()) {
                st.pop();
            }
            if(st.empty())
                ans[i] = -1;
            else
                ans[i] = st.top();
            
            st.push(nums[i]);
        }

        for(int i = nums.size() - 1; i > maxIndex; i--) {
            while(!st.empty() && nums[i] >= st.top()) {
                st.pop();
            }
            if(st.empty())
                ans[i] = -1;
            else
                ans[i] = st.top();
            
            st.push(nums[i]);
        }
        return ans;
    }
};