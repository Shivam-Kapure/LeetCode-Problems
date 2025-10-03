class Solution {
private:
    void backtrack(int& numSolutions, vector<short>& rows, int col, int& n) {
        if (col == n) {
            numSolutions += 1;
            return;
        }
        for (int i = 0; i < n; i ++) {
            if (checkValidPos(rows, i, col, n)) {
                rows[col] = i;
                backtrack(numSolutions, rows, col + 1, n);
            }
            rows[col] = -1;
        }
    }

    bool checkValidPos(vector<short>& rows, int row, int col, int& n) {
        // Check the column
        if (rows[col] != -1) return false;

        // check the row
        for (int i = 0; i < n; i ++) {
            if (rows[i] == row) return false;
        }

        // check diagonals
        // lower right
        for (int i = row + 1, j = col + 1; i < n && j < n; i++, j++) {
            if (rows[j] == i) return false;
        }

        //lower left
        for (int i = row + 1, j = col - 1; i < n && j >= 0; i++, j--) {
            if (rows[j] == i) return false;
        }

        // upper right
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (rows[j] == i) return false;
        }

        // upper left
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (rows[j] == i) return false;
        }

        return true;
    }

public:
    int totalNQueens(int n) {
        vector<short> rows(n, -1);
        int col = 0;
        int numSolutions = 0;
        backtrack(numSolutions, rows, col, n);
        return numSolutions;
    }
};