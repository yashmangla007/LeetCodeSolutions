class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low= 0, mid= 0, high= n-1;
        while(mid<=high){   // --> used while loop
            if(nums[mid] == 1) mid++;
            else if(nums[mid] ==0){
                //swap(nums[mid], nums[low])
                int temp = nums[mid];
                nums[mid] =nums[low];
                nums[low] = temp;
                low++;
                mid++;
            }
            else if(nums[mid] ==2){
                //swap(nums[mid], nums[low])
                int temp = nums[mid];
                nums[mid] =nums[high];
                nums[high] = temp;

                high--;
            }
        }
    }
};