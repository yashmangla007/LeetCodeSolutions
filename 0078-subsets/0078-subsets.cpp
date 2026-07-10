class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> powerset;
        
        for(int mask = 0; mask < (1<<n); mask++){
            vector<int> subset;
            int temp = mask, i=0;
            while(temp>0){
                if(temp&1) subset.push_back(nums[i]);
                i++;
                temp= temp>>1;
            }
            powerset.push_back(subset);
        }

        return powerset;
    }
};