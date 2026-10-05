class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        if(s.size()>1) st.push(0);
        else return 0;

        for(int it : s){
            
            if(it=='('){
                st.push(0);
            }

            else{
                int x = st.top();
                st.pop();
                int value = 0;
                if(x==0) value =1;
                else value = 2*x;

                st.top() += value;
            }

        }

        return st.top();
    }
};