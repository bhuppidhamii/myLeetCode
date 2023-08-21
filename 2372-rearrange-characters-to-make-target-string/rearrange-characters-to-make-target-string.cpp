class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        map<char,int>m1;
        for(auto ch:s){
            m1[ch]++;
        }

        map<char,int>m2;
        for(auto ch:target){
            m2[ch]++;
        }
        
        int ans=INT_MAX;
        for(auto ch:target){
            int x=m1[ch];
            int y=m2[ch];

            int res=floor(x/y);
            ans=min(res, ans);
        }
        return ans;
    }
};