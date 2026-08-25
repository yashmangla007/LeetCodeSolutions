class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<bool> check(n+1, false);

        for(int i=0; i<n; i++){
            if(nums[i]%k==0){
                
                int x = nums[i]/k;
                
                if(x<=n){
                    check[x] = true;
                }
            }
        }

        for(int i=1; i<=n; i++){
            if(check[i]==false){
                return k*i;
            }
        }

        return k*(n+1);

    }
};