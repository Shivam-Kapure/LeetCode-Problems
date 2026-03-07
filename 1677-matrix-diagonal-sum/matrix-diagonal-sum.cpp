class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int r = mat.size(); int ans = 0;

        for(int i = 0; i < mat.size(); i++) {
            ans += mat[i][i];  
            if(i != (r - i - 1))
                ans += mat[i][r - i -1];      
        }
        return ans;
    }
};