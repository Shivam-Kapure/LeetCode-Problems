class Solution {
public:
    vector<string> ans;
    vector<string> digitsMapped = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void helperBT(int idx, string currStr, string& digits) {
        if(currStr.length() == digits.length()) {
            ans.push_back(currStr);
            return;
        }
        string chars = digitsMapped[digits[idx] - '0'];
        for(char c : chars)
            helperBT(idx + 1, currStr + c, digits);
    }

    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return ans;
        helperBT(0, "", digits);
        return ans;
    }
};