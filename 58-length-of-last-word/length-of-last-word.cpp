class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        for(int i = s.length() - 1; i >= 0; i--) {
            if(s[i] != ' ') {
            count++;
            }
            else {
                if(count >= 1) {
                    return count;
                }
            }
        }
        return count;   
    }
};