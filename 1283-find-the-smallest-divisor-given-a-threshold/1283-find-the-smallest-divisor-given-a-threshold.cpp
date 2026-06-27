class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        int maxn= nums[0], ans=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>maxn) maxn = nums[i];
        }

        int low=1, high= maxn, mid;
        while(low<=high){
            mid = low + ((high-low)/2);
            long long sum =0;

            for(int i=0; i<nums.size(); i++){
                if(nums[i]%mid ==0 ) sum += nums[i]/mid;
                else sum += (nums[i]/mid) + 1;
            }

            if(sum<= threshold){
                ans = mid;
                high= mid-1;
            }
            else low = mid+1;
            
        }

        return ans;
    }
};