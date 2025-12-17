class Solution {
public:
    string minWindow(string s, string t) {
        int left = 0; int right = 0;
        int m = s.length(); int n = t.length();
        int hash[256] = {0}; int count = n;
        int startidx = -1; int minlen = INT_MAX;

        if(m < n)
            return "";
        
        for(char c : t)
            hash[c]++;
        
        while(right < m) {
            if(hash[s[right]] > 0)
                count--;
            hash[s[right]]--;
            right++;

            while(count == 0) {
                if((right - left) < minlen) {
                    minlen = (right - left);
                    startidx = left;
                }
                hash[s[left]]++;
                if(hash[s[left]] > 0)
                    count++;
                left++;
            }
        }
        if(startidx != -1)
            return s.substr(startidx, minlen);
        else
            return "";
    }
};