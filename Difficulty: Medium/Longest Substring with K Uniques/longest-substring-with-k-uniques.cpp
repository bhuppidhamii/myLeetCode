class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // Jai Shri Ram
        
        map<char, int>mp;
        int i = 0, max_len = -1, N = s.size();
        
        for(int j=0; j<N; j++){
            mp[s[j]]++;
            
            if(mp.size() == k){
                int len = j-i+1;
                max_len = max(max_len, len);
            }
            
            while(i < N && mp.size() > k){
                mp[s[i]]--;
                if(mp[s[i]] == 0){
                    mp.erase(s[i]);
                }
                i++;
            }
        }
        return max_len;
    }
};