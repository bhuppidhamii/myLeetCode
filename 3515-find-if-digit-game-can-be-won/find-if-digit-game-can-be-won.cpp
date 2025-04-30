class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int sumSingleDigit = 0;
        int sumDoubleDigit = 0;

        for (auto& n : nums) {
            if (to_string(n).size() == 1) {
                sumSingleDigit += n;
            } else {
                sumDoubleDigit += n;
            }
        }
        int a1 = sumSingleDigit, a2 = sumDoubleDigit;
        int b1 = sumSingleDigit, b2 = sumDoubleDigit;

        if (a1 > b2 || a2 > b1) {
            return true;
        }
        return false;
    }
};