class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0, high = arr.size()-1, mid;
        int ans = -1;
        while(low<=high){
            mid = low + ((high -low)/2);
            int missed = arr[mid] - (mid+1);
            
            if(missed<k) low = mid+1;
            else high = mid-1;
        }

        return low+k;
    }
};