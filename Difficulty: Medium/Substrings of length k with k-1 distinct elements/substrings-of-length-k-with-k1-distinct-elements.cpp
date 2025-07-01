class Solution {
  public:
    int substrCount(string &s, int k) {
        // Jai Shri Ram
        vector<int>v(26, 0);
        
        // increase count+1 if you increase any count from 0
        // decrease count-1 if you reduce any count to 0
        int c = 0;
        for(int i=0; i<k; i++){
            int idx = s[i]-'a';
            if(v[idx] == 0) c++;
            v[idx]++; // increase frequency
        }
        int ans = 0;
        // cout<<c;
        if(c == k-1) ans++;
        
        int i=0;
        for(int j=k; j<s.size(); j++){
            int idx = s[i]-'a';
            v[idx]--; // decrease frequency
            if(v[idx] == 0){
                c--;
            }
            i++;
            
            if(v[s[j]-'a'] == 0) c++;
            v[s[j]-'a']++; // increase frequency
            
            if(c == k-1) ans++; // check
        }
        return ans;
    }
};