class Solution {
  public:
    int smallestSubstring(string s) {
        // Jai Shri Ram
        int n=s.size();
        unordered_map<char,int>mp;
        int ans = INT_MAX;
        int i = 0;
        for(int j=0; j<n; j++){
            mp[s[j]]++;
            
            while(mp.size() == 3){
                int len=(j-i+1);
                ans = min(ans, len);
                
                mp[s[i]]--;
                if(mp[s[i]]==0) mp.erase(s[i]);
                i++;
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
