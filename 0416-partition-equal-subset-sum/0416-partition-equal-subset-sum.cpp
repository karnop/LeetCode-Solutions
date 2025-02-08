class Solution {
public:
    bool helper(int i, int s, vector<int>& nums, vector<vector<int>> &dp) { 
        if(s == 0) return true;
        if(s < 0) return false;
        if(i == 0) return nums[i] == s;
        if(dp[i][s] != -1) return dp[i][s];

        return dp[i][s] = helper(i-1, s, nums, dp) || helper(i-1, s-nums[i], nums, dp);
    }
    bool canPartition(vector<int>& nums) {
        long long sum = 0; 
        for(int i=0; i<nums.size(); i++) {
            sum+=nums[i];
        }   

        if(sum&1) return false;
        vector<vector<int>> dp(nums.size(), vector<int>((sum/2) + 1, -1));
        return helper(nums.size()-1, sum/2, nums, dp);
    }
};