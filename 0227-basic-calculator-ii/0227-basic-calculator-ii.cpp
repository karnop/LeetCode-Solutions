class Solution {
public:
    int calculate(string s) {
        stack<int> st;

        int num = 0;
        char lastSign = '+';

        int n = s.size();
        for(int i=0; i<n; i++) {
            char ch = s[i];

            if(isdigit(ch)) {
                num = (num*10) + (ch - '0'); 
            }

            // operator or a last characte
            if((!isdigit(ch) && ch != ' ') || i == n-1) {
                
                if(lastSign == '+') st.push(num);
                
                else if(lastSign == '-') st.push(-num);
                
                else if(lastSign == '*') {
                    int temp = st.top();
                    st.pop();
                    st.push(temp*num);
                }

                else if(lastSign == '/') {
                    int temp = st.top();
                    st.pop();
                    st.push(temp/num);
                }

                lastSign = ch;
                num = 0;
            }
        }

        int res = 0;
        while(!st.empty()) {
            res += st.top();
            st.pop();
        }

        return res;
    }
};