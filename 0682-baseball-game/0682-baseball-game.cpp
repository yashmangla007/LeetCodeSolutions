class Solution {
public:

    int valueifInt(string s){
        if(s[0]=='+' || s[0]=='D'|| s[0]=='C') return 0;

        int value=0, end;
        bool isneg = false;
        if(s[0]=='-'){
            end=1;
            isneg = true;
        }
        else end=0;
        for(int pval = 1, i=s.size()-1; i>=end; i--, pval*=10){
            value += (s[i]-'0')*pval;
        }   

        if(isneg) return value*(-1);
        else return value;
    }

    int calPoints(vector<string>& operations) {
        stack<int> st;

        for(int i=0; i<operations.size(); i++){
            int x = valueifInt(operations[i]);
            if(x){
                st.push(x);
            }

            else if(operations[i]=="+"){
                int sum = st.top();
                int prev = st.top();
                st.pop();
                sum += st.top();
                st.push(prev);
                st.push(sum);
            }

            else if(operations[i]=="D"){
                st.push(st.top()*2);
            }

            else{
                st.pop();
            }

        }

        int ans = 0;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};