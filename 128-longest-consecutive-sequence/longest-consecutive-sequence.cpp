class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, int> mp;
        for (auto& n : nums) {
            mp[n]++;
        }
        vector<int> v;
        for (auto& i : mp) {
            v.push_back(i.first);
        }

        int N = v.size();
        // if(N==0) return 0;
        int ans = 0;
        int i = N - 1;
        while (i >= 0) {
            int count = 1;
            int j = i-1;
            while(j >= 0 && v[j]+1 == v[j+1]){
                j--;
                count++;
            }
            ans = max(ans, count);
            i = j;
        }
        return ans;
    }
};