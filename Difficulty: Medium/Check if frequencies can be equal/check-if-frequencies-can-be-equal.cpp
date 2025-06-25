class Solution {
  public:
    bool sameFreq(string& s) {
        // Jai Shri Ram
        vector<int>v(26,0);
        for(auto &ch:s){
            v[ch-'a']++;
        }
        int minFreq=INT_MAX;
        int maxFreq=INT_MIN;
        for(int i=0; i<26; i++){
            if(v[i] > 0){
                minFreq=min(minFreq, v[i]);
            }
            
            maxFreq=max(maxFreq, v[i]);
        }
        
        int minFreqCount = 0;
        int maxFreqCount = 0;
        for(int i = 0; i < 26; i++){
            if(v[i] == minFreq){
                minFreqCount++;
            }
            
            if(v[i] == maxFreq){
                maxFreqCount++;
            }
        }
        // cout<<maxFreq<<" "<<minFreq;
        if(maxFreq - minFreq == 0) return true;
        
        // Case A - 1 char occurs exactly 1 more time (k, k+1, k)
        if((maxFreq-minFreq) == 1 && maxFreqCount == 1){
            return true;
        }
        
        // Case B - 1 char occurs exactuly once and all k time (1, k, k)
        if((maxFreq-minFreq) == 1 && (minFreq == 1 && minFreqCount == 1)){
            return true;
        }
        
        return false;
    }
};