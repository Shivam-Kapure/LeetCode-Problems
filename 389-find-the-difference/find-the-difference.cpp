class Solution {
public:
    char findTheDifference(string s, string t) {  
        unordered_map<char, int> freq;
        for(char one : t) {
            freq[one]++;
        }
        for(char two : s) {
            freq[two]--;
        }
        for(auto it : freq) {
            if(it.second != 0)
                return it.first;
        }
        return ' ';
    }
};