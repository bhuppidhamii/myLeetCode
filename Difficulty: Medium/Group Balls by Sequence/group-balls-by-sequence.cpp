class Solution {
  public:
    bool validgroup(vector<int> &arr, int k) {
        // Jai Shri Ram
        int N=arr.size();
        if(N % k != 0) return false; 
        
        map<int,int>mp;
        for(auto &i:arr){
            mp[i]++;
        }
        
        for(auto &i:mp){
            int val=i.first;
            int freq=i.second;
            
            if(mp[val] == 0) continue;
            
            for(int i = 0; i < k; i++){
                int nextVal = val+i;
                
                if(mp[nextVal] < freq){
                    return false;
                }
                
                mp[nextVal] -= freq;
            }
        }
        return true;
    }
};