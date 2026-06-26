class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int ans =1;
        
        //Finding k upperbound
        int m = piles[0];
        for(int i=1; i<piles.size(); i++){
            if(piles[i]>m) m= piles[i];
        }

        int low=1, high=m;
        long long mid;
        while(low<=high){
            mid = low + ((high-low)/2);
            long long t=0;
            
            //Calculating Time for each k
            for(int i=0; i<piles.size(); i++){
                if(piles[i]%mid ==0) t += piles[i]/mid;
                else t += (piles[i]/mid) + 1;
            }

            if(t<=h){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }

        return ans;

    }
};