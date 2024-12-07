class Solution {
public:
    bool isPalindrome(int x) {
        int count = 1;  
    int rev = 0; 

    int temp = x;
    
    if(x<0) return false;

    while(x){
        int rem = x%10;
        if(rev > (INT32_MAX/10) || rev < (INT32_MIN/10)) {cout << 0 ; break;}
        rev = rev*10;
        rev+= rem;
        count++;
        x = x/10;
    }

    return rev == temp;
    }
};