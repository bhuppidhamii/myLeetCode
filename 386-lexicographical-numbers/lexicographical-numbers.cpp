class Solution {
public:
    vector<int> ans;
    void solve(int startNum, int n) {
        if (startNum > n) {
            return;
        }
        ans.push_back(startNum);
        for (int append = 0; append <= 9; append++) {
            int newNum = (startNum * 10) + append;
            solve(newNum, n);
        }
    }
    vector<int> lexicalOrder(int n) {
        for (int startNum = 1; startNum <= 9; startNum++) {
            solve(startNum, n);
        }
        return ans;
    }
};