class Solution {
  public:
    int atMost(int k, string &s){
        int n = s.size();
        int i = 0, ans = 0;
        vector<int>mp(26,0);
        int distinct = 0;
        for(int j=0; j<n; j++){
            if(mp[s[j]-'a']==0) distinct++;
            mp[s[j]-'a']++;
            
            while(i<n && (int)distinct > k){
                mp[s[i]-'a']--;
                if(mp[s[i]-'a'] == 0)distinct--;
                i++;
            }
            int count = j-i+1;
            ans += count;
        }
        return ans;
    }
    int countSubstr(string& s, int k) {
        // Jai Shri Ram
        return atMost(k,s)-atMost(k-1,s);
    }
};