class Solution {
public:
    void helper(string digits, string temp, unordered_map<char, string> &map, vector<string> &ans)
{
    if(digits == ""){
        if(!temp.empty())
        ans.push_back(temp);
        return;
    }

    string digs = map[digits[0]];

    for(int i=0; i<digs.size(); i++)
    {
        temp.push_back(digs[i]);
        helper(digits.substr(1), temp, map, ans);
        temp.pop_back();
    }

}

vector<string> letterCombinations(string digits) {
    unordered_map<char, string> map;
    map['2'] = "abc";
    map['3'] = "def";
    map['4'] = "ghi";
    map['5'] = "jkl";
    map['6'] = "mno";
    map['7'] = "pqrs";
    map['8'] = "tuv";
    map['9'] = "wxyz";

    vector<string> ans;
    helper(digits, "", map, ans);
    return ans;
}
};