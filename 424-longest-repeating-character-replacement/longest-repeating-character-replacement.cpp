class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0; int maxlen = 0; int maxfreq = 0;
        int count[26] = {0};

        for(int right = 0; right < s.length(); right++) {
            count[s[right] - 'A']++;
            maxfreq = max(count[s[right] - 'A'], maxfreq);

            while((right - left + 1) - maxfreq > k) {
                count[s[left] - 'A']--;
                left++;
            }
            maxlen = max(maxlen, (right - left + 1));
        }
        return maxlen;
    }
};