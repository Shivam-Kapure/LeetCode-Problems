class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int> st;

        for(auto n : num) {
            while(!st.empty() && k > 0 && st.top() > n) {
                st.pop();
                k--;
            }
            st.push(n);
        }

        while(!st.empty() && k > 0) {
            st.pop();
            k--;
        }

        while(st.empty()) return "0";

        string ans = "";

        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        while(ans.size() > 0 && ans.back() == '0')
            ans.pop_back();
        
        if(ans.size() == 0) return "0";
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};