class Solution {
public:

    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> preMax(n), postMax(n);
        preMax[0] = height[0];
        postMax[n-1] = height[n-1];
        for(int i=1, j=n-2; i<n; i++,j--){
            if(preMax[i-1]<height[i]){
                preMax[i] = height[i];
            }
            else {
                preMax[i] = preMax[i-1];
            }
            
            if(postMax[j+1]<height[j]){
                postMax[j] = height[j];
            }
            else {
                postMax[j] = postMax[j+1];
            }
        }

        int ans =0;
        
        for(int i=0; i<n; i++){
            ans += min(preMax[i],postMax[i])-height[i]; 
        }

        return ans;
    }
};