class Solution {
public:
    int longestBalanced(string s) {
        int size = s.length();
        int max_len = 0;

        for(int l = 0; l < size; l++) {
            int max_freq = 0;
            int unique = 0;
            vector<int> freq(26, 0);

            for(int r = l; r < size; r++) {
                int char_idx = s[r] - 'a';

                if(freq[char_idx] == 0)
                    unique++;

                freq[char_idx]++;
                max_freq = max(max_freq, freq[char_idx]);

                int curr_len = r - l + 1;

                if(curr_len == max_freq * unique)
                    max_len = max(max_len, curr_len);
            }
        } 
        return max_len;
    }
};