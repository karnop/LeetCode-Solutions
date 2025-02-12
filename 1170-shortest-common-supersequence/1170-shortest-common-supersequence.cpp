class Solution {
public:
    void lcs(string s1, string s2, vector<vector<int>> &dp) {
        for(int i=1; i<=s1.size(); i++) {
            for(int j=1; j<=s2.size(); j++) {
                if(s1[i-1] == s2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else {
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }
    }

    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        lcs(str1, str2, dp);

        string ans = "";
        while(n > 0 && m > 0) {
            if(str1[n-1] == str2[m-1]) {
                ans = str1[n-1] + ans;
                n--; m--;
            }
            else if(dp[n-1][m] > dp[n][m-1]) {
                ans = str1[n-1] + ans;
                n--;
            }
            else {
                ans = str2[m-1] + ans;
                m--;
            }
        }

        while(m > 0) {ans = str2[m-1] + ans; m--;} 
        while(n > 0) {ans = str1[n-1] + ans; n--;}

        return ans; 
    }
};