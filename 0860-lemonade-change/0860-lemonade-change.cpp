class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        int fivec=0, tenc=0, satisfy=0;
        for(int i=0; i<n; i++){
            if(bills[i]==5){
                fivec++;
                satisfy++;
            }
            else if(bills[i]==10 && fivec>0){
                tenc++;
                fivec--;
                satisfy++;
            }

            else{
                if(tenc>0 && fivec>0){
                    tenc--;
                    fivec--;
                    satisfy++;
                }
                else if(fivec>=3){
                    fivec -= 3;
                    satisfy++;
                }
            }
        }

        if(satisfy==n) return true;
        else return false;
    }
};