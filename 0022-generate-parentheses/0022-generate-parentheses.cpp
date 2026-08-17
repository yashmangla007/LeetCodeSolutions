class Solution {
public:
    void findCombo(string s, int open, int close, int n, vector<string>& ans){
        if(s.length() == 2*n) {
            ans.push_back(s);
        }

        if(open<n){
            findCombo(s+'(', open+1, close, n, ans);
        }

        if(close<open){
            findCombo(s+')', open, close+1, n, ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        findCombo("", 0, 0, n, ans);
        return ans;
    }
};