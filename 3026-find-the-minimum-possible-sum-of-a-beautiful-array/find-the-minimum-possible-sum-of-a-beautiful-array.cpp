class Solution {
public:
    long long minimumPossibleSum(int n, int k) {
       vector<int> ans;
        map<int, int> m;
        if (n == 1) return n;

        ans.push_back(1);
        m[1] = 1;
        int num = 2;
        int i = 1;

        while (i < n) {
            if (m.find(num) == m.end() && m.find(k - num) == m.end()) {
                ans.push_back(num);
                m[num]++;
                i++;
            }
            num++;
        }

        long sum = 0;
        for (auto i : ans) {
            sum += i;
        }
        return sum; 
    }
};