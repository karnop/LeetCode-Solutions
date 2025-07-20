class Solution {
public:
    // brute force : O(n^3)
    vector<vector<int>> bruteForce(vector<int>& nums) {
        set<vector<int>> s;
        for(int i=0; i<nums.size(); i++) 
            for(int j=i+1; j<nums.size(); j++) 
                for(int k=j+1; k<nums.size(); k++) 
                    if(nums[i] + nums[j] + nums[k] == 0) {
                        vector<int> temp = {nums[i], nums[j], nums[k]};
                        sort(temp.begin(), temp.end());
                        s.insert(temp);
                    }

        return vector<vector<int>>(s.begin(), s.end());
    }

    // optimized 2 ptr : O(nlogn + n^2)
    vector<vector<int>> optimized(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        for(int i=0; i<nums.size()-2; i++) {
            int j = i+1, k = nums.size()-1;
            while(j < k) {
                long long int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0) {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    sort(temp.begin(), temp.end());
                    s.insert(temp);
                    j++; k--;
                }
                else if(sum < 0) j++;
                else k--;
            }
        }

        return vector<vector<int>>(s.begin(), s.end());
    }


    vector<vector<int>> threeSum(vector<int>& nums) {
        // return bruteForce(nums);
        return optimized(nums);
    }
};