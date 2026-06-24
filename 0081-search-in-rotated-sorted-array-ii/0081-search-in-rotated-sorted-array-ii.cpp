class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int low= 0, high= n-1, mid;
        while(low<=high){
            mid = low + ((high-low)/2);

            if(nums[mid] == target) return true;

            //To remove ambiguities by duplicates
            if(nums[low]==nums[mid] && nums[mid]==nums[high]){  
                low++;
                high--;
                continue;
            }

            if(nums[low]<=nums[mid]){        //means left half sorted!!
                if(nums[low]<=target && nums[mid]>target){
                    high = mid-1;
                }
                else low = mid+1;
            }

            else{           // means right of the mid is sorted
                if(nums[mid]<target && nums[high]>=target) low = mid+1;
                else high = mid-1;
            }

        }

        return false;
    }
};