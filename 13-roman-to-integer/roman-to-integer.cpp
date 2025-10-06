class Solution {
public:
    int romanToInt(string s) {
        unordered_map <char, int> rome = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, 
        {'C', 100}, {'D', 500}, {'M', 1000}};
        int result = 0;
        for(int i = 0; i < s.length(); i++) {
            auto a = rome.find(s[i]);
            if(a != rome.end()) {
                if(i + 1 < s.length()) {
                    auto b = rome.find(s[i + 1]);
                    if(a->second < b->second) {
                        int c = b->second - a->second;
                        result = result + c;
                        ++i;
                        continue;
                    }
                }
                result = result + a->second;
            }
        }
        return result;
    }
};