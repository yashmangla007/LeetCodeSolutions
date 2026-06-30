class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int maxw = weights[0];
        int totalw = weights[0];
        for(int i=1; i<weights.size(); i++){
            if(weights[i]>maxw) maxw = weights[i];
            totalw += weights[i];
        }
        int low = maxw, high= totalw, mid;
        int ans = 0;

        while(low<=high){
            mid = low + ((high-low)/2);
            int daysum=0, day=1;
            for(int i=0; i<weights.size(); i++){
                if(daysum+weights[i]<=mid) daysum += weights[i];
                else{
                    day++;
                    daysum=weights[i];
                }
            }

            if(day<=days) {
                ans =mid;
                high = mid-1;
            }
            else low = mid+1;
        }

        return ans;
    }
};