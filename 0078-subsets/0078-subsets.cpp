class Solution {
public:

    void getPowerSet(int ind, vector<int> &curset, vector<vector<int>> &powerset, vector<int> &nums){
        if(ind>= nums.size()){
            powerset.push_back(curset);
            return;
        }

        curset.push_back(nums[ind]);
        getPowerSet(ind+1, curset, powerset, nums);
        curset.pop_back();
        getPowerSet(ind+1, curset, powerset, nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> powerset;
        vector<int> curset;
        getPowerSet(0, curset, powerset, nums);

        return powerset;
    }
};