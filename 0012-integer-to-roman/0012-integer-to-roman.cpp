class Solution {
public:
    string intToRoman(int num) {
        string ans = "";

        // thousand
        int m = num/1000;
        ans += string(m, 'M');
        num = num % 1000;

        // hundreds
        int c = num/100;
        if(c < 4) ans += string(c, 'C');
        if(c == 4) ans += "CD";
        if(c > 4 && c < 9) ans += ("D" +  string(c%5, 'C'));
        if(c == 9) ans += "CM";
        num  = num%100;

        // tens
        int x = num/10;
        if(x < 4) ans += string(x, 'X');
        if(x == 4) ans += "XL";
        if(x > 4 && x < 9) ans += ("L" + string(x%5, 'X'));
        if(x == 9) ans += "XC";
        num = num%10;

        int i = num;
        if(i < 4) ans += string(i, 'I');
        if(i == 4) ans += "IV";
        if(i > 4 && i < 9) ans += ("V" + string(i%5, 'I'));
        if(i == 9) ans += "IX";

        return ans;
    }
};