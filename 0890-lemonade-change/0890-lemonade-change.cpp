class Solution {
public:
    
bool lemonadeChange(vector<int>& bills) {
    int a = 0, b = 0;
    for(int i = 0; i<bills.size(); i++){
        if(bills[i] == 5) {
            a++;
        }
        else if(bills[i] == 10) {
            b++;
            if(a  >= 1) a--;
            else return false;
        }
        else if(bills[i] == 20) {
            if(b >= 1 && a >= 1) {b--; a--;}
            else if(a>= 3) a = a-3;
            else return false;
        }
    }   
    return true; 
}


};