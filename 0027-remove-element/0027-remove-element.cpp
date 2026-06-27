class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = nums.size();
        for(int i=0; i<k; i++){
            if(nums[i]==val){
                for(int j=i; j<k-1; j++ ){
                    nums[j]=nums[j+1];
                }
                k--;
                i--;
            }
        }
        return k;
    }
};