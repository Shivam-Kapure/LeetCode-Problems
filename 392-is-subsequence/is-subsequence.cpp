class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sp = 0; int tp = 0;
        if(s == "") {
            return true;
        }
        if(t == "") {
            return false;
        }
        if(s.length() == 1 && t.length() == 1) {
            return s[sp] == t[tp];
        }
        for(int tp = 0; tp < t.length(); tp++) {
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