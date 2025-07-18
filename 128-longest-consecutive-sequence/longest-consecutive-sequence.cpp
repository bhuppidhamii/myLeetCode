class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int ans = 0;
        for (int n : st) {
            if (st.find(n - 1) == st.end()) { // n-1 is not present in map
                // n is the start of the seq;
                int length = 1;
                while (st.find(n + length) != st.end()) { // go till the end of seq
                    length++;
                }
                ans = max(ans, length);
            }
        }
        return ans;
    }
};