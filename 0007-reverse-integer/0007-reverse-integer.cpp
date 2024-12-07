class Solution {
public:
    int reverse(int x) {
        int count = 1;  
    int rev = 0; 
    

    while(x){
        int rem = x%10;
        if(rev > INT32_MAX/10 || rev < INT32_MIN/10) return 0;
        rev *= 10;
        rev+= rem;
        count++;
        x = x/10;
    }

    return rev;
    }
};