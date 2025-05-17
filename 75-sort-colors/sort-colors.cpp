class Solution {
public:
    void sortColors(vector<int>& nums) {
        // optimal approach
        int N = nums.size();
        int i = 0;     // for handling 0
        int j = 0;     // for handling 1
        int k = N - 1; // for handling 2

        while (j <= k) {
            if(nums[j] == 1){
                j++;
            }else if(nums[j] == 2){
                swap(nums[j], nums[k]);
                k--;
            }else if(nums[j] == 0){
                swap(nums[j], nums[i]);
                i++;
                j++;
            }
        }
    }
};