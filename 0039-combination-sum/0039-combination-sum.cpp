class Solution {
public:
void helper(int index, int sum, vector<int> temp, vector<int>& candidates, int target, vector<vector<int>>& ans)
{
    if(sum > target) return;
    if(sum == target) {
        ans.push_back(temp);
        return;
    }
    if(index == candidates.size()) return;

    temp.push_back(candidates[index]);
    helper(index, sum+candidates[index], temp, candidates, target, ans);
    temp.pop_back();
    helper(index+1, sum, temp, candidates, target, ans);
    
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> temp;
    helper(0, 0, temp, candidates, target, ans);
    return ans;
}
};