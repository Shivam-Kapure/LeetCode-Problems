class Solution {
public:
    bool detectCapitalUse(string word) {
        int UC_count = 0;
        for(char c : word) {
            if(isupper(c))
                UC_count++;
        }

        if(UC_count == word.length())
            return true;
        if(UC_count == 0)
            return true;
        if(UC_count == 1 && isupper(word[0]))
            return true;
        
        return false;
    }
};