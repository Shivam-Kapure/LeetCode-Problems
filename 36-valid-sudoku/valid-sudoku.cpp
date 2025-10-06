class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int col[9][9] = {0};
        int row[9][9] = {0};
        int square[9][9] = {0};

        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                int num = board[i][j] - '1';
                int k = (i/3)*3 + (j/3);
                if(board[i][j] == '.') {
                    continue;
                }
                else {
                    if(col[j][num] < 1) {
                        col[j][num] = 1;
                    }
                    else {
                        return false;
                    }
                    if(row[i][num] < 1) {
                        row[i][num] = 1;
                    }
                    else {
                        return false;;
                    }
                    if(square[k][num] < 1) {
                        square[k][num] = 1;
                    }
                    else {
                        return false;;
                    }
                }
            }
        }
        return true;
    }
};