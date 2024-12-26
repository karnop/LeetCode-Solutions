class Solution {
public:
    bool canJump(vector<int>& nums) {
    if(nums[0] == 0 && nums.size() > 1) return false;
    
    int high = 0, low = 0;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] == 0) low = i;
        else low = max(i+1, low);
        high = max(i + nums[i], high);
        if(high >= nums.size()-1) return true;
        if(nums[i] == 0 && low == high) return false; 
    }  
    return false;
}

};