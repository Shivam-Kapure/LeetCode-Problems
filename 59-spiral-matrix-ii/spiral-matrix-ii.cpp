class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        int row1 = 0, col1 = 0;
        int row2 = n - 1, col2 = n - 1;
        int num = 1;

        while (row1 <= row2 && col1 <= col2) {
            for (int i = col1; i <= col2; i++)
                ans[row1][i] = num++;

            for (int i = row1 + 1; i <= row2; i++)
                ans[i][col2] = num++;

            if (row1 < row2) {
                for (int i = col2 - 1; i >= col1; i--)
                    ans[row2][i] = num++;
            }

            if (col1 < col2) {
                for (int i = row2 - 1; i > row1; i--)
                    ans[i][col1] = num++;
            }

            row1++; col1++;
            row2--; col2--;
        }
        return ans;
    }
};
