class Solution {
public:
    string largestGoodInteger(string s) {
        // BF
        int N = s.size();
        string ans = "";
        for (int i = 0; i < N - 2; i++) {
            if (s[i] == s[i + 1] && s[i + 1] == s[i + 2]) {
                // it's a good integer
                string str = s.substr(i,3);
                if (ans.size() == 0) {
                    ans = str;
                } else {
                    // compare
                    int n1 = stoi(ans);
                    int n2 = stoi(str);
                    if (n2 > n1) {
                        ans = str;
                    }
                }
            }
        }
        return ans;
    }
};