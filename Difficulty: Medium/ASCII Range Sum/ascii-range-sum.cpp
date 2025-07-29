class Solution {
  public:
    vector<int> asciirange(string& s) {
        // Jai Shri Ram
        
        int N = s.size();
        
        // store the freq
        vector<int>freq(26, 0);
        for(auto &ch:s){
            freq[ch-'a']++;
        }
        
        // store the 1st occ
        vector<int>first(26, -1);
        for(int i=0; i<N; i++){
            char ch = s[i];
            if(first[ch-'a'] == -1){
                first[ch-'a'] = i;
            }
        }
        
        // store the last occ
        vector<int>last(26, 0);
        for(int i=0; i<N; i++){
            char ch = s[i];
            // keep updating index
            last[ch-'a'] = i;
        }
        
        // store all the commulative ascii sum
        vector<int>sum(N, 0);
        sum[0] = 97 + (int)(s[0]-'a');
        for(int i=1; i<N; i++){
            int ascii = 97 + (int)(s[i]-'a');
            sum[i] = sum[i-1] + ascii;
        }
        
        
        vector<int>ans;
        for(int i=0; i<N; i++){
            // freq must be > 1
            char ch = s[i];
            if(freq[ch-'a'] > 1){
                int a = first[ch-'a'];
                int b = last[ch-'a'];
                
                int result = sum[b-1] - sum[a];
                if(result > 0){
                    ans.push_back(result);
                }
                
                // reset the occurences/frequencies
                freq[ch-'a'] = 0;
            }
        }
        return ans;
    }
};