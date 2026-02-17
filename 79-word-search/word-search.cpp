class Solution {
public:
    int ROWS, COLS;
    //vector<vector<bool>> visited;

    bool helperBT(vector<vector<char>>& board, string word, int r, int c, int idx) {
        if(idx == word.length())
            return true;

        if(r < 0 || c < 0 || r >= ROWS || c >= COLS || board[r][c] == '#' || board[r][c] != word[idx])
            return false;
        
        board[r][c] = '#';
        bool res = helperBT(board, word, r + 1, c, idx + 1) ||
                   helperBT(board, word, r - 1, c, idx + 1) ||
                   helperBT(board, word, r, c + 1, idx + 1) ||
                   helperBT(board, word, r, c - 1, idx + 1);
        board[r][c] = word[idx];

        return res;
    }

    bool exist(vector<vector<char>>& board, string word) {
        ROWS = board.size(); COLS = board[0].size();
        //visited = vector<vector<bool>>(ROWS, vector<bool>(COLS, false));

        for(int r = 0; r < ROWS; r++) {
            for(int c = 0; c < COLS; c++) {
                if(helperBT(board, word, r, c, 0))
                    return true;
            }
        }
        return false;
    }
};