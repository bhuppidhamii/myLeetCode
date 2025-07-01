class Solution {
  public:
    int substrCount(string &s, int k) {
        // Jai Shri Ram
        if(k > s.size()) return 0;
        
        map<char, int>mp;
        for(int i=0; i<k; i++){
            mp[s[i]]++;
        }
        
        int count=0;
        if(mp.size() == k-1){
            count++;
        }
        
        int i=0;
        for(int j=k; j<s.size(); j++){
            mp[s[i]]--;
            if(mp[s[i]] == 0){
                mp.erase(s[i]);
            }
            i++;
            
            mp[s[j]]++;
            if(mp.size() == k-1){
                count++;
            }
        }
        return count;
    }
};