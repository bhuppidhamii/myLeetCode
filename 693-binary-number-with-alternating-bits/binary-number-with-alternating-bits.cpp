class Solution {
public:
    bool hasAlternatingBits(int n) {
        vector<int> arr;
        while (n > 0) {
            if (n & 1 == 1) {
                arr.push_back(1);
            } else {
                arr.push_back(0);
            }
            n = n >> 1;
        }
        for (int i = 0; i < arr.size() - 1; i++) {
            if (arr[i] == arr[i + 1]) {
                return false;
            }
        }
        return 1;
    }
};