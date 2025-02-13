class Solution {
public:

    int helper(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
        if(j == 0) return i; // 1 based indexing
        if(i == 0) return j;
        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i-1] == s2[j-1]) return dp[i][j] = helper(i-1, j-1, s1, s2, dp);

        // insert, delete, replace
        return dp[i][j] = 1 + min( { helper(i, j-1, s1, s2, dp), helper(i-1, j, s1, s2, dp), helper(i-1, j-1, s1, s2, dp) } );
    }

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return helper(n, m, word1, word2, dp);
    }
};