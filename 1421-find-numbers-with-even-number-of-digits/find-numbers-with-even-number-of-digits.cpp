class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for (auto& n : nums) {
            int sz = to_string(n).size();
            if (sz % 2 == 0) {
                count++;
            }
        }
        return count;
    }
};