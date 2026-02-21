class Solution {
public:
    void dfsHelper(vector<vector<bool>>& visited, vector<vector<char>>& grid, int r, int c, int i, int j) {
        if(i < 0 || j < 0 || i >= r || j >= c)
            return;
        if(visited[i][j] == true || grid[i][j] != '1')
            return;
        
        visited[i][j] = true;

        dfsHelper(visited, grid, r, c, i - 1, j);
        dfsHelper(visited, grid, r, c, i, j + 1);
        dfsHelper(visited, grid, r, c, i + 1, j);
        dfsHelper(visited, grid, r, c, i, j - 1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int islandCount = 0;
        int r = grid.size(); int c = grid[0].size();
        vector<vector<bool>> visited(r, vector<bool>(c, false));

        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(grid[i][j] == '1' && !visited[i][j]) {
                    dfsHelper(visited, grid, r, c, i, j);
                    islandCount++;
                }
            }
        }
        return islandCount;
    }
};