class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int r=0, l=0, fliped = 0, maxlen =0;
        int n = nums.size();
        while(r<n){
            
            if(nums[r]==0){
                fliped++;
            }

            while(fliped>k){
                if(nums[l]==0){
                    fliped--;
                }
                l++;
            }

            maxlen = max(r-l+1, maxlen);

            r++;
        } 

        return maxlen;
    }
};