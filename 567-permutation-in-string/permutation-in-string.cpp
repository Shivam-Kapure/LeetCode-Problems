class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k = s1.length(); int left = 0; int count[26] = {0};

        if(k > s2.length())
            return false;

        for(char c : s1) {
            count[c - 'a']++;
        }
        
        for(int right = 0; right < s2.length(); right++) {
            count[s2[right] - 'a']--;

            if((right - left + 1) > k) {
                count[s2[left] - 'a']++;
                left++;
            }

            if((right - left + 1) == k) {
                bool result = true;
                for(int i = 0; i < 26; i++) {
                    if(count[i] != 0) {
                        result = false;
                        break;
                    }
                }
                if(result)
                    return true;
            }
        }
        return false;
    }
};