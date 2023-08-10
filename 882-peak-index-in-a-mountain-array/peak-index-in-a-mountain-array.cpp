class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
        int N=nums.size();
        int low=0;
        int high=N-1;

        while(low<=high){
            int mid = low + (high - low) / 2;
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]){
                return mid;
            }else if(nums[mid] > nums[mid-1]){
                low=mid+1;
            }else{
                high=mid;
            }
        }
        return -1;
    }
};