class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int smaller = 0;
        int count = 0;

        for(int i=0 ; i<nums.size() ; i++){
            if(nums[i]<target) smaller++;
            else if(nums[i]==target) count++;
        }

        vector<int> ans;

        int i=0;
        while(count>0){
            ans.push_back(smaller+i);
            i++;
            count--;
        }
        return ans;
    }
};