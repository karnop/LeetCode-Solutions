class Solution {
public:
    int helper(int n, vector<int>& dp, vector<int>& nums){
        if(n == 0) return nums[0];
        if(n < 0) return 0;
        if(dp[n] != -1) return dp[n];

        int pick = nums[n] + helper(n-2, dp, nums);
        int notPick = helper(n-1, dp, nums);

        dp[n] = max(pick, notPick);
        return dp[n];

    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return helper(n-1, dp, nums);
    }
};