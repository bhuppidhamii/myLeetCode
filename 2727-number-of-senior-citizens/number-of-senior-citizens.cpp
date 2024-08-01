class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt = 0;
        for (auto d : details) {
            int age = (d[11] - '0') * 10 + (d[12] - '0');
            if (age > 60) {
                cnt++;
            }
        }
        return cnt;
    }
};