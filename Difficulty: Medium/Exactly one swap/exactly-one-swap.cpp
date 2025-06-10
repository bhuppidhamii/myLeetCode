class Solution {
  public:
    int countStrings(string &s) {
        // Jai Shri Ram  
        int N=s.size();
        unordered_map<char,int>mp;
        for(auto &ch:s){
            mp[ch]++;
        }
        if(mp.size() == 1){
            return 1;
        }
        if(mp.size() == N){
            return (N*(N-1))/2;
        }
        int count=1;
        for(int i=0; i<N-1; i++){
            mp[s[i]]--;
            int res= (N - (i+1) - mp[s[i]]);
            count+=res;
        }
        return count;
    }
};
