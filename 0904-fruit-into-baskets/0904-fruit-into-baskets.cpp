class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int cf1=-1, cf2=-1;
        int pf1= -1, pf2= -1;
        int maxlen =0, j=0;

        for(int i=0; i<fruits.size(); i++){
            if(cf1==-1) cf1 = fruits[i];
            if(cf2==-1) cf2 = fruits[i];

            if(fruits[i]==cf1) pf1 = i;
            else if(fruits[i]==cf2) pf2= i;

            else{
                if(pf1<pf2){
                    j = pf1+1;
                    pf1 = pf2;
                    pf2 = i;
                    cf1 = cf2;
                    cf2 = fruits[i];
                }
                else{
                    j= pf2+1;
                    pf2 = i;
                    cf2 = fruits[i];
                }
            }
            
            maxlen = max(maxlen, i-j+1);
        }

        return maxlen;
    }
};