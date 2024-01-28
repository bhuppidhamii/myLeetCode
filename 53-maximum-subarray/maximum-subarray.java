class Solution {
    public int maxSubArray(int[] nums) {
        int max_store = Integer.MIN_VALUE, max_sum = 0;

        for(int i = 0; i < nums.length; i++) {
            max_sum = max_sum + nums[i];

            if( max_sum > max_store ) max_store = max_sum;

            if( max_sum < 0 ) max_sum = 0;
        }
        
        return max_store;
    }
}