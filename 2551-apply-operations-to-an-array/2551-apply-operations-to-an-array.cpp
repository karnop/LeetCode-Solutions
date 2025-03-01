class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        int zeros = 0;
        for(int i=0; i<n-1; i++) {
           if(nums[i] == nums[i+1]) {
                nums[i] *= 2;
                nums[i+1] = 0;
           }
        }
        
        // 2 pointer approach
        int index = 0;
        for(int i=0; i<n; i++) {
            if(nums[i] != 0) {
                nums[index] = nums[i];
                index++;
            }
        }
        while(index < n) {
            nums[index] = 0;
            index++;
        }
        return nums;
    }
};