class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // Jai Shri Ram
        int n= s.size();
        int max_len = -1;
        int i=0, j=0;
        unordered_map<int,int>mp;
        
        for(int j=0; j<n; j++){
            mp[s[j]]++;
            
            while(i<n && mp.size() > k){
                mp[s[i]]--;
                if(mp[s[i]] == 0) mp.erase(s[i]);
                i++;
            }
            
            if(mp.size() == k){
                int len = j-i+1;
                if(len > max_len){
                    max_len = len;
                }
            }
        }
        return max_len;
    }
};