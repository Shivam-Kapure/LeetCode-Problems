class Solution {
public:
    vector<int> dx = {-1, -1, -1};
    vector<int> dy = {-1, 0, 1};
    int d = dx.size();

    bool isValid(vector<vector<char>> &board, int i, int j, int n) {
        for (int k = 0; k < d; k++) {
            int x = i + dx[k], y = j + dy[k];
            while (x > -1 && x < n && y > -1 && y < n) {
                if (board[x][y] == 'Q') {return false;}
                x += dx[k];
                y += dy[k];
            }
        }
        return true;
    }

    vector<string> construct(vector<vector<char>> &grid, int n) {
        vector<string> ans;
        for (int i = 0; i < n; i++) {
            string line(grid[i].begin(), grid[i].end());
            ans.push_back(line);
        }
        return ans;
    }

    void backtrack(vector<vector<string>> &ans, vector<vector<char>> &cur, int i, int n) {
        if (i == n) {
            ans.push_back(construct(cur, n));
            return;
        }
        for (int j = 0; j < n; j++) {
            if (isValid(cur, i, j, n)) {
                cur[i][j] = 'Q';
                backtrack(ans, cur, i + 1, n);
                cur[i][j] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<vector<char>> temp(n, vector<char>(n, '.'));
        backtrack(ans, temp, 0, n);
        return ans;
    }
};