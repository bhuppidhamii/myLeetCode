class Solution {
  public:
    int at_most(string s, int k){
        int N=s.size(), i = 0, j = 0, count = 0;
        unordered_map<char, int>mp;
        
        while(j < N){
            mp[s[j]]++;
            
            while(mp.size() > k){
                mp[s[i]]--;
                if(mp[s[i]] == 0){
                    mp.erase(s[i]);
                }
                i++;
            }
            // Count substrings ending at j with at most k distinct characters
            count += (j - i + 1);
            
            j++;
        }
        return count;
    }
    int countSubstr(string& s, int k) {
        // code here.
        // cout<<at_most(s, k)<<"\n";
        // cout<<at_most(s, k-1)<<"\n";
        return at_most(s, k) - at_most(s, k-1);
    }
};