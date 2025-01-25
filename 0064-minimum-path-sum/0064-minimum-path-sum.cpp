class Solution {
public:
    long long int helper(int r, int c, vector<vector<int>>&dp, vector<vector<int>>&grid) {
        if(r == 0 && c == 0) return grid[r][c];
        if(r < 0 || c < 0) return INT_MAX;
        if(dp[r][c] != -1) return dp[r][c];

        int up = helper(r-1, c, dp, grid);
        int left = helper(r, c-1, dp, grid);

        return dp[r][c] = grid[r][c] +  min(up, left);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, -1));
        return helper(rows-1, cols-1, dp, grid);
    }
};