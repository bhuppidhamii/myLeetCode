class Solution {
  public:
    int romanToDecimal(string &s) {
        // Jai Shri Ram
        
        unordered_map<char,int>mp;
        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;
        
        stack<int>st;
        int ans = 0;
        for(auto &ch:s){
            if(st.empty()){
                st.push(mp[ch]);
            }else{
                
                // if coming element is smaller
                    // then, add stack to ans and pop it
                        // push the coming element
                        if(!st.empty() && st.top() > mp[ch]){
                            ans+=st.top();
                            st.pop();
                            st.push(mp[ch]);
                        }else if(!st.empty() && mp[ch] > st.top()){
                            int res = mp[ch]-st.top();
                            st.pop();
                            ans+=res;
                        }else if(!st.empty() && mp[ch] == st.top()){ 
                            // same aa jayee -> MMXX
                            int res = st.top();
                            st.pop();
                            res+=mp[ch];
                            st.push(res);
                        }
            }
        }
        // remove remaining elements
        while(st.size()>0){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};