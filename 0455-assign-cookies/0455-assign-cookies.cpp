class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int count=0;
        int cooki=0, child=0;
        while(cooki<s.size() && child<g.size()){
            if(s[cooki]>=g[child]){
                count++;
                child++;
            }           
            cooki++; 
        }
        return count;
    }
};