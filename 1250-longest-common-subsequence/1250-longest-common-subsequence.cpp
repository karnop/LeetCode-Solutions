class Solution {
public:
    int helperMemoization(int i1, int i2, string t1, string t2, vector<vector<int>>&dp) {
        if(i1<0 || i2<0) return 0;
        if(dp[i1][i2] != -1) return dp[i1][i2];

        if(t1[i1] == t2[i2]) return dp[i1][i2] = 1 + helperMemoization(i1-1, i2-1, t1, t2, dp);
        return dp[i1][i2] = max(helperMemoization(i1-1, i2, t1, t2, dp) , helperMemoization(i1, i2-1, t1, t2, dp));
    }

    int helperTabulation(string t1, string t2, vector<vector<int>>&dp) {
        for(int i=0; i<=t1.size(); i++) dp[i][0] = 0;
        for(int i=0; i<=t2.size(); i++) dp[0][i] = 0;

        for(int i1=1; i1<=t1.size(); i1++){
            for(int i2=1; i2<=t2.size(); i2++) {
                // if same
                if(t1[i1-1] == t2[i2-1]) 
                dp[i1][i2] = 1 + dp[i1-1][i2-1];
                // not same
                else dp[i1][i2] = max(dp[i1-1][i2] , dp[i1][i2-1]);
            }
        }
        return dp[t1.size()][t2.size()];
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1, -1));
        return helperTabulation(text1, text2, dp);
    }
};