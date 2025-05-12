class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int N = digits.size();
        set<int> st;
        for (int i = 0; i < N; i++) {
            int a = digits[i];
            for (int j = 0; j < N; j++) {
                int b = digits[j];
                for (int k = 0; k < N; k++) {
                    int c = digits[k];
                    if (i != j && j != k && i != k) {
                        int num = a * 100 + b * 10 + c * 1;
                        if (num >= 100 && num < 999 && num % 2 == 0) {
                            st.insert(num);
                        }
                    }
                }
            }
        }
        vector<int> ans(begin(st), end(st));
        return ans;
    }
};