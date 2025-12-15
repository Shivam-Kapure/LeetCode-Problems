class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0; int maxfreq = 0; int maxlen = 0;
        unordered_map<char, int> freq {0};

        for(int r = 0; r < s.length(); r++) {
            freq[s[r]]++;
            maxfreq = max(maxfreq, freq[s[r]]);

            while((r - left + 1) - maxfreq > k) {
                freq[s[left]]--;
                left++;
            }

            maxlen = max(maxlen, (r - left + 1));
        }
        return maxlen;
    }
};