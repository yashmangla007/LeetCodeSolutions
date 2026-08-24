class Solution {

    void findComb(int ind,int target, vector<int> &arr, vector<int> &candidates, vector<vector<int>> &ans ){
        if(target==0){
            ans.push_back(arr);
            return;
        }

        for(int i=ind; i<candidates.size(); i++){
            
            if(candidates[i]>target) break;
            
            if(i>ind && candidates[i]==candidates[i-1]) continue;

            arr.push_back(candidates[i]);
            findComb(i+1, target-candidates[i], arr, candidates, ans);
            arr.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> arr;
        sort(candidates.begin(), candidates.end());
        findComb(0, target, arr, candidates, ans);
        return ans;
    }
};