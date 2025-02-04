class Solution {
public:
    int helper(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp)  {
        if(i == triangle.size()-1) return triangle[i][j];

        int down = dp[i+1][j], diag = dp[i+1][j+1];
        if(down == -1) down = helper(i+1, j, triangle, dp);
        if(diag == -1) diag = helper(i+1, j+1, triangle, dp);

        return dp[i][j] = triangle[i][j] + min(down, diag);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(), vector<int>(triangle.size(), -1));
        return helper(0, 0, triangle, dp);
    }
};