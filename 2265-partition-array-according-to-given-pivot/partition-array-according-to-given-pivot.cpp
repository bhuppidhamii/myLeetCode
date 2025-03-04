class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        int i = 0;     // less than pivot;
        int j = n - 1; // more than pivot;

        vector<int> res(n, 0);
        int left = 0, right = n - 1;
        while (i < n && j >= 0) {
            if (nums[i] < pivot) {
                res[left] = nums[i];
                left++;
            }
            if (nums[j] > pivot) {
                res[right] = nums[j];
                right--;
            }
            i++, j--;
        }
        for (int i = left; i <= right; i++) {
            res[i] = pivot;
        }
        return res;
    }
};