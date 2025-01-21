class Solution {
public:
    int helper(int n, vector<int>& dp, vector<int>& nums){
        if(n == 0) return nums[0];
        else if(n < 0) return 0;
        if(dp[n] != -1) return dp[n];

        int pick = nums[n] + helper(n-2, dp, nums);
        int notPick = helper(n-1, dp, nums);

        dp[n] = max(pick, notPick);
        return dp[n];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> t1, t2;
        for(int i=0; i<n; i++) {
            if(i!=0) t1.push_back(nums[i]);
            if(i!=n-1) t2.push_back(nums[i]);
        }
        vector<int> dp(n, -1);
        vector<int> dp2(n, -1);
        bool flag = true;
        return max(helper(t1.size()-1, dp, t1), helper(t2.size()-1, dp2, t2));
    }
};