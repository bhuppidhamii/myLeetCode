class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int N = nums.size();

        unordered_set<int> st;
        for (int i = N - 1; i >= 0; i--) {
            if (st.count(nums[i])) { // duplicate found
                int no_of_elements = i + 1;
                return ceil(no_of_elements / 3.0);
            }
            st.insert(nums[i]);
        }
        return 0;
    }
};