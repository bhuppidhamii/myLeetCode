class Solution {
public:
    bool checkStrictlyIncreasing(vector<int>&nums, int low, int high){
        for(int i=low+1; i<=high; i++){
            if(nums[i] <= nums[i-1]) return false;
        }
        return true;
    }
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        // Jai Shri Ram
        int n = nums.size();
        if(k > n)return false;
        for(int i=0; i<=n-2*k; i++){
            // check from every index
            if(checkStrictlyIncreasing(nums, i, i+k-1) && checkStrictlyIncreasing(nums, i+k, i+k+k-1)){
                cout<<i<<", "<<i+k-1<<"\n";
                cout<<i+k<<", "<<i+k+k-1;
                return true;
            }
        }
        return false;
    }
};