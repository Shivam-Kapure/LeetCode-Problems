class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        for(auto currDigit : num){
            while(!st.empty() && k>0 && st.top()>currDigit){
                st.pop();
                k--;
            }
            st.push(currDigit);
        }
        // element left
        while(!st.empty() && k>0){
                st.pop();
                k--;
        }
        // edge case 
        if(st.empty()) return "0";
        string ans = "";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        // trimming zeroes
        while(ans.size()>0 && ans.back()=='0'){
            ans.pop_back();
        }
        if(ans.empty()) return "0";
        reverse(ans.begin(),ans.end());
        return ans;
    }
};