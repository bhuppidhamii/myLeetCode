class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }

        string say = countAndSay(n - 1);

        // processing  ---->
        int N = say.size();
        int i = 0;
        string res = "";
        for (i = 0; i < N; i++) {
            char ch = say[i];
            int count = 1;

            while (i < N - 1 && say[i] == say[i + 1]) {
                count++;
                i++;
            }
            res += to_string(count) + string(1, ch);
        }
        return res;
    }
};