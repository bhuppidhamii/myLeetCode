class Solution {
  public:
    int minValue(string &s, int k) {
        // Jai Shri Ram
        map<char, int>mp;
        for(auto &ch:s){
            mp[ch]++;
        }
        
        // max-heap
        priority_queue<pair<int,char>>pq;
        for(auto &i:mp){
            char ch=i.first;
            int freq=i.second;
            pq.push({freq, ch});
        }
        
        while(pq.size() > 0 && k > 0){
            pair<int,char> p = pq.top();
            int freq = p.first;
            char ch = p.second;
            
            pq.pop();
            
            freq-=1;
            if(freq > 0){
                pq.push({freq, ch});
            }
            k--;            
        }
        int ans=0;
        while(pq.size()>0){
            pair<int,char> p=pq.top();
            pq.pop();
            int freq=p.first;
            ans+=(freq*freq);
        }
        return ans;
    }
};