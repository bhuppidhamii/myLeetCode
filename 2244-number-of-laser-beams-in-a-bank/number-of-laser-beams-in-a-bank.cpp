class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int N = bank.size();
        vector<int> v;
        for (int i = 0; i < N; i++) {
            int count1s = 0;
            for (auto ch : bank[i]) {
                if (ch == '1') {
                    count1s++;
                }
            }
            if (count1s != 0) {
                v.push_back(count1s);
            }
        }
        if(v.size()==0 ||v.size()==1){
            return 0;
        }
        int ans = 0;
        for (int i = 0; i < v.size() - 1; i++) {
            int prod = v[i] * v[i + 1];
            ans += prod;
        }
        return ans;
    }
};