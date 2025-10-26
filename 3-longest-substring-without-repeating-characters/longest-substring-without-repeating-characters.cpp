class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0; int right = 0;
        int ans = 0;
        vector<int> count (256, 0);
        while(right < s.length()) {
            count[s[right]]++;
            while(count[s[right]] > 1) {
                count[s[left]]--;
                left++;
            }
            ans = max(ans, right - left + 1);       
            right++;
        }
        return ans;
    }
};