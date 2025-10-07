class Solution {
public:
    bool isValid(string s) {
        if(s.length() % 2 == 1) {
            return false;
        }
        stack<char> st;
        for(char c : s) {
            if(st.empty()) {
                if(c == '{' || c == '(' || c == '[') {
                    st.push(c);
                }
                else {
                    return false;
                }
            }
            else {
                if(c == '{' || c == '(' || c == '[') {
                    st.push(c);
                }
                else if(c == '}' && st.top() == '{' || c == ')' && st.top() == '(' || c == ']' 
                && st.top() == '[') {
                    st.pop();
                }
                else {
                    return false;
                }
            }
        }
        if(st.empty()) {
            return true;
        }
        else {
            return false;
        }
    }
};