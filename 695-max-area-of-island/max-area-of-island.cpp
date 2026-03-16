class Solution {
public:
    int dfsHelper(int i, int j, vector<vector<bool>>& visited, vector<vector<int>>& grid, int r, int c) {
        if(i < 0 || j < 0 || i >= r || j >= c)
            return 0;
        
        if(visited[i][j] == true || grid[i][j] != 1)
            return 0;
        
        visited[i][j] = true;

        return 1 + dfsHelper(i - 1, j, visited, grid, r, c)
                 + dfsHelper(i, j + 1, visited, grid, r, c)
                 + dfsHelper(i + 1, j, visited, grid, r, c)
                 + dfsHelper(i, j - 1, visited, grid, r, c);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area = 0;
        int r = grid.size();
        int c= grid[0].size();

        vector<vector<bool>> visited(r, vector<bool>(c, false));

        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(!visited[i][j] && grid[i][j] == 1) {
                    area = max(area, dfsHelper(i, j, visited, grid, r, c));
                } 
            }
        }
        return area;
    }
};