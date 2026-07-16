    class Solution {
    public:
        vector<int> nextGreaterElement(
            vector<int>& nums1, vector<int>& nums2) {
            stack <int> nge;
            unordered_map<int, int> mp;
            int n = nums2.size();

            for(int i= n-1; i>=0; i--){
                while(!nge.empty() && nge.top()<=nums2[i]){
                    nge.pop();
                }

                if(nge.empty()){
                    mp[nums2[i]] = -1;
                }

                else{
                    mp[nums2[i]] = nge.top();
                }

                nge.push(nums2[i]);

            }

            vector<int> ans(nums1.size());
            for(int i=0; i<nums1.size(); i++){
                ans[i] = mp[nums1[i]];
            }

            return ans;
        }
    };