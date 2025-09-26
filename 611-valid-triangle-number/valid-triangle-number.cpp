class Solution {
public:
    int binarySearch(int low, int high, vector<int>&nums, int sum){
        int ans = -1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(sum > nums[mid]){
                ans = mid;
                low = mid+1;
            }else{
                high = mid-1;
            }   
        }
        return ans;
    }
    int triangleNumber(vector<int>& nums) {
        sort(begin(nums), end(nums));

        int n = nums.size();
        if(n < 3) return 0;
        
        int count = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int sum = nums[i]+nums[j]; // a+b

                // use binary search to find c > a+b
                int res = binarySearch(j+1, n-1, nums, sum);
                if(res == -1) continue;

                count+=(res-j);
            }
        }
        return count;
    }
};