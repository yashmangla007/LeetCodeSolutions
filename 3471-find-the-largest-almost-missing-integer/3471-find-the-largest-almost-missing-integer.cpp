class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int> windowCount;

        int l = 0, r = k - 1;

        while (r < nums.size()) {
            unordered_set<int> seen;

            for (int i = l; i <= r; i++) {
                seen.insert(nums[i]);
            }
            for (int x : seen) {
                windowCount[x]++;
            }

            l++;
            r++;
        }

        int ans = -1;

        for (auto &[num, count] : windowCount) {
            if (count == 1) {
                ans = max(ans, num);
            }
        }

        return ans;
    }
};