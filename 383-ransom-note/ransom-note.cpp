class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int count[26] = {0};
        for(char m : magazine) {
            count[m - 'a']++;
        }
        for(char r : ransomNote) {
            count[r - 'a']--;
        }
        for(int i = 0; i < 26; i++) {
            if(count[i] < 0)
                return false;
        }
        return true;
    }
};