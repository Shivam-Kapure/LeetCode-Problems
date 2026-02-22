class Solution {
public:
    int dfsHelper(vector<vector<int>>& grid, vector<vector<bool>>& visited, int r, int c, int i, int j) {
        if(i < 0 || j < 0 || i >= r || j >= c || visited[i][j] == true || grid[i][j] != 1)
            return 0;

        visited[i][j] = true;

        return 1 + dfsHelper(grid, visited, r, c, i - 1, j) 
                 + dfsHelper(grid, visited, r, c, i, j + 1) 
                 + dfsHelper(grid, visited, r, c, i + 1, j) 
                 + dfsHelper(grid, visited, r, c, i, j - 1);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r = grid.size(); int c = grid[0].size();
        vector<vector<bool>> visited(r, vector<bool>(c, false));
        int area = 0;
        
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(grid[i][j] == 1 && !visited[i][j]) {
                    area = max(area, dfsHelper(grid, visited, r, c, i , j));
                }
            }
        }
        return area;
    }
};