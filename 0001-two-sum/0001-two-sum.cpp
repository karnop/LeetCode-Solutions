class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for(int i=0; i<nums.size(); i++) {
            int complement  = target - nums[i];
            if(map.count(complement) != 0) {
                return {i, map[complement]};
            }
            map[nums[i]] = i;
        }
        return {};
    }
};