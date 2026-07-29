class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long msum = INT_MIN;
        long long csum=0;
        for(int i =0; i<nums.size(); i++){
            csum += nums[i];
            if(csum>msum) msum = csum;
            if(csum<0) csum =0;
        }

        return msum;
    }
};