class Solution {
public:
    void solve(string& curr, vector<string>& all, int n) {
        if (curr.size() == n) {
            all.push_back(curr);
            return;
        }

        for (char ch = '0'; ch <= '1'; ch++) {
            // do
            curr.push_back(ch);

            // explore
            solve(curr, all, n);

            // undo
            curr.pop_back();
        }
    }
    string findDifferentBinaryString(vector<string>& nums) {
        // BF
        // generate all the binary strings &
        // then check each on of them if they are present or not

        vector<string> all;
        string curr = "";
        int n = nums.size();

        solve(curr, all, n);

        for (auto& s1 : all) {
            bool isPresent = false;
            for (auto& s2 : nums) {
                if (s1 == s2) {
                    isPresent = true;
                    break;
                }
            }
            if (isPresent == false) {
                return s1;
            }
        }
        return "";
    }
};