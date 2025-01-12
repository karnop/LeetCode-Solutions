class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis) {
        if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || vis[row][col] == 1 || grid[row][col] == 0) return;
        
        vis[row][col] = 1;

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        for(int i=0; i<4; i++){
            int nrow = row+delrow[i];
            int ncol = col+delcol[i];

            dfs(nrow, ncol, grid, vis);
        }

    }
    int numEnclaves(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> vis(rows, vector<int>(cols, 0));

        for(int i=0; i<rows; i++) {
                if(vis[i][0] == 0 && grid[i][0] == 1) dfs(i, 0, grid, vis);
                if(vis[i][cols-1] == 0 && grid[i][cols-1] == 1) dfs(i, cols-1, grid, vis);
        }
        for(int i=0; i<cols; i++) {
                if(vis[0][i] == 0 && grid[0][i] == 1) dfs(0, i, grid, vis);
                if(vis[rows-1][i] == 0 && grid[rows-1][i] == 1) dfs(rows-1, i, grid, vis);
        }


        int ans = 0;
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if(grid[i][j] == 1 && vis[i][j] == 0) ans++;
            }
        }
        return ans;
    }
};