class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        int zeros = 0;
        vector<int> ans;
        for(int i=0; i<n-1; i++) {
            if(nums[i] == 0) {
                zeros++;
                continue;
            }
            else if(nums[i] == nums[i+1]) {
                nums[i] *= 2;
                nums[i+1] = 0;
            }
            ans.push_back(nums[i]);
        }
        ans.push_back(nums[n-1]);
        for(int i=0; i<zeros; i++) ans.push_back(0);
        return ans;
    }
};