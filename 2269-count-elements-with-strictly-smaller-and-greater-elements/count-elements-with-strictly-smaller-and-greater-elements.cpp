class Solution {
public:
    int countElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        map<int,int>m;
        for(auto i:nums){
            m[i]++;
        }
        set<int>s;
        for(auto i:nums){
            s.insert(i);
        }
        vector<int>v={s.begin(), s.end()};
        int count=0;
        int n=v.size();
        for(int i=1;i<n-1;i++){
            count+=m[v[i]];
        }

        return count;
    }
};