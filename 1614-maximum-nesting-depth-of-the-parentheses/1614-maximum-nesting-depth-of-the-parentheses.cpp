class Solution {
public:
    int maxDepth(string s) {
        
        int openc = 0, maxcount = 0;

        for(int i=0 ; i<s.size(); i++){
            if(s[i]=='(') openc++;
            else if(s[i]==')') openc--;
            maxcount = max(openc, maxcount);
        }

        return maxcount;
    }
};