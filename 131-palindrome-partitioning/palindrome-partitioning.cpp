class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0; int right = s.length() - 1;
        while(left <= right) {
            if(s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }

    void getAllParts(string s, vector<string>& partitions, vector<vector<string>>& ans) {
        if(s.length() == 0) {
            ans.push_back(partitions);
            return;
        }
        for(int i = 0; i < s.length(); i++) {
            string part = s.substr(0, i + 1);
            if(isPalindrome(part)) {
                partitions.push_back(part);
                getAllParts(s.substr(i + 1, s.length() - 1), partitions, ans);
                partitions.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<string> partitions;
        vector<vector<string>> ans;
        getAllParts(s, partitions, ans);
        return ans;
    }
};