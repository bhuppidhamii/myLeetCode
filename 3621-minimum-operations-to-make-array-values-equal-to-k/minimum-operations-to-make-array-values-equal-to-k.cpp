class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        set<int> st;

        for (auto& n : nums) {
            if (n < k) {
                return -1;
            } else if (n > k) {
                st.insert(n);
            }
        }
        return st.size();
    }
};