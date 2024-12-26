class Solution {
public:
    bool checkValidString(string s) {
    int min = 0, max = 0;

    for(char x : s) {
        if(x == '(') {
            min++; max++;
        }

        else if(x == ')') {
            min--; max--;
        }

        else if (x == '*') {
            min--;
            max++;
        }

        if(max < 0) return false;
        if(min < 0) min = 0;
    }

    if(min == 0) return true;
    return false;
}
};