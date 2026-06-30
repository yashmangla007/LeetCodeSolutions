class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        unordered_map<int, int> map;

        for (int num : nums) {
            map[num]++;
        }                   // O(n)

        vector<int> ans(nums.size());

        for(int i=0; i<nums.size(); i++){
            int j = 0, count=0;
            while(j<nums[i]){
                if(map[j]>0) count+=map[j];
                j++;
            }
            ans[i] = count;
        }

        return ans;
    }
};