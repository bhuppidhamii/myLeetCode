class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int N = nums.size();
        int count = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i != j) {
                    string a = nums[i];
                    string b = nums[j];
                    if (a + b == target) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};