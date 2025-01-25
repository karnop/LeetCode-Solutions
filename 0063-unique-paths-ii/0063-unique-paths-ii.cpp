class Solution {
public:

    long long int helper(int r, int c, vector<vector<long long int>>& dp, vector<vector<int>>& obstacleGrid){
        if(r == 0 && c == 0) {
            if(obstacleGrid[0][0] == 1) return 0;
            return 1;
        }

        if(r < 0 || c < 0) return 0;
        if(dp[r][c] != -1) return dp[r][c];

        if(obstacleGrid[r][c] == 1) 
            return dp[r][c] = 0;

        long long int up = helper(r-1, c, dp, obstacleGrid);
        long long int left = helper(r, c-1, dp, obstacleGrid);
        return dp[r][c] = up+left;

    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();
        vector<vector<long long int>> dp(rows, vector<long long int>(cols, -1));
        return helper(rows-1, cols-1, dp, obstacleGrid);
    }
};