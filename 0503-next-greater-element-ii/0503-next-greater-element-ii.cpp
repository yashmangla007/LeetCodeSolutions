class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;  
        int n = nums.size();
        vector<int> ans(n);


        for(int i = 2*n-1; i>=0; i--){
            int ind = i%n;
            while(!st.empty() && nums[ind]>=st.top()){
                st.pop();
            }
            if(st.empty() && i<n){
                ans[i] = -1;
            }
            if(!st.empty() && i<n){
                ans[i] = st.top();
            }
            st.push(nums[ind]);
        }
        return ans;
    }
};