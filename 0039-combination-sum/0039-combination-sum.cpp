class Solution {
public:
    void combSum (int ind, vector<int> &arr, vector<vector<int>> &ans, vector<int> candidates, int target, int csum){
        //Base condition
        if(ind>=candidates.size() || csum>target){
            if(csum == target){
                ans.push_back(arr);
                return;
            }
            else return;
        }
        arr.push_back(candidates[ind]);
        csum += candidates[ind];
        combSum(ind, arr, ans, candidates, target, csum);
        
        arr.pop_back();
        csum -= candidates[ind];
        combSum(ind+1, arr, ans, candidates, target, csum);

        return;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> arr;
        combSum(0, arr, ans, candidates, target, 0);

        return ans;   
    }
};