class Solution {
public:
    void generator(vector<string>& v, int opening_count, int closing_count, int n, string s) {
        if(opening_count == n && closing_count == n) {
            v.push_back(s);
            return;
        }
        if(opening_count < n) {
            generator(v, opening_count + 1, closing_count, n, s + "(");
        }
        if(closing_count < opening_count) {
            generator(v, opening_count, closing_count + 1, n, s + ")");
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generator(result, 0, 0, n, "");
        return result;
    }
};