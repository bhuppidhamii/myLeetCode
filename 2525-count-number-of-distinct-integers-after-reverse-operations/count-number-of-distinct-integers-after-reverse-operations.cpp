class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        int N = nums.size();
        for (int i = 0; i < N; i++) {
            string s = to_string(nums[i]);
            reverse(s.begin(), s.end());
            nums.push_back(stoi(s));
        }
        set<int> s;
        for (auto i : nums) {
            s.insert(i);
        }
        return s.size();
    }
};