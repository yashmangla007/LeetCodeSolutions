class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inccount = 0, deccount = 0;
        int mxinc = 1, mxdec = 1;
        for(int i=1; i<nums.size(); i++){
            if(nums[i]>nums[i-1]){
                inccount++;
                mxinc = max(mxinc, inccount+1);
                deccount=0;
            }
            
            else if(nums[i]<nums[i-1]){
                deccount++;
                mxdec = max(mxdec, deccount+1);
                inccount=0;
            }

            else{
                inccount=0;
                deccount=0;
            }

        }
        return max(mxinc, mxdec);
    }
};