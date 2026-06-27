class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {

        //impossible case to save time:
        if(bloomDay.size()/k<m) return -1;

        //finding max and min of bloomday
        int maxday = bloomDay[0], minday= bloomDay[0];
        for(int i = 1; i<bloomDay.size(); i++){
            if(bloomDay[i]>maxday) maxday = bloomDay[i];
            if(bloomDay[i]<minday) minday = bloomDay[i];
        }

        //BS on 1 to max for finding day;
        int low=minday, high=maxday, ans=-1;
        long long day;
        while(low<=high){
            day = low + ((high-low)/2);
            int flower=0, count=0;
            
            for(int i=0; i<bloomDay.size(); i++){
                
                if(bloomDay[i]<=day) flower++;
                else flower=0;

                if (flower==k){
                    count++;
                    flower=0;   //Reset post 1 bouqet
                }

            }

            if(count >= m){
                ans=day;
                high = day-1;
            }
            else low = day+1;

        }
        return ans;      
    }
};