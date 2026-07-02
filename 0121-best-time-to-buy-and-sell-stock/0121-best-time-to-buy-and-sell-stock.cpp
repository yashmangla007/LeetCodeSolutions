class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        int prevMin = prices[0], curProfit =0, maxProfit=0;
        for(int i=1; i<n; i++){
            curProfit = prices[i] - prevMin;
            if(curProfit > maxProfit) maxProfit = curProfit;
            if(curProfit<0) prevMin = prices[i]; 
        }
        return maxProfit;
    }
};