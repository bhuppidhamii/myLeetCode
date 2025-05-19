class Solution {
public:
    bool checkValidTriangle(vector<int>& nums) {
        bool isValid = false;
        int a = nums[0];
        int b = nums[1];
        int c = nums[2];
        // The condition for a valid triangle is that for any two sides, the sum
        // of their lengths must be greater than the third side.
        if ((a + b > c) && (b + c > a) && (a + c > b))
            isValid = true;

        return isValid;
    }
    string triangleType(vector<int>& nums) {
        if (checkValidTriangle(nums) == false) {
            return "none";
        }
        int a = nums[0];
        int b = nums[1];
        int c = nums[2];

        map<int, int> mp;
        for (auto& i : nums) {
            mp[i]++;
        }
        if (mp.size() == 1)
            return "equilateral";
        if (mp.size() == 2)
            return "isosceles";
        if (mp.size() == 3)
            return "scalene";

        return "hehe";
    }
};