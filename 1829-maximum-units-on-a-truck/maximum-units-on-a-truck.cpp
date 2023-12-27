class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(),[&](auto a, auto b) { return a[1] > b[1]; });
        for (auto& b : boxTypes) {
            cout << b[0] << "-" << b[1] << "  ";
        }
        int ans = 0;
        for (auto& b : boxTypes) {
            if (truckSize <= 0)
                break;
            if (truckSize >= b[0]) {
                ans += (b[0] * b[1]);
                truckSize -= b[0];
            } else {
                ans += (truckSize * b[1]);
                truckSize -= truckSize;
            }
        }
        return ans;
    }
};