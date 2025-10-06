class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sp = 0; int tp = 0;
        for(tp = 0; tp < t.length(); tp++) {
            if(s[sp] == t[tp]) {
                sp++;
            }
        }
        if(sp == s.length()) {
            return true;
        }
        return false;
    }
};