class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> map;
        
        int left = 0;
        for(int right=0; right<n; right++) {
            // adding 
            map[nums[right]]++;

            // removing
            if(right-left > k) {
                map[nums[left]]--;
                left++;
            }

            // checking
            if(map[nums[right]]>=2) return true;
        }
        return false;
    }
};