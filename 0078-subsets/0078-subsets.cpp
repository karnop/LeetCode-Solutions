class Solution {
public:
void subsets(int ind, vector<int>temp, vector<int>v, vector<vector<int>> &ans)
{
    if(ind == v.size())
    {
        ans.push_back(temp);
        return;
    }

    subsets(ind+1, temp, v, ans);
    temp.push_back(v[ind]);
    subsets(ind+1, temp, v, ans);
}

    vector<vector<int>> subsets(vector<int>& nums) {
     vector<int> temp;
     vector<vector<int>> ans;
    
    subsets(0, temp, nums, ans);
    return ans;
    }
};