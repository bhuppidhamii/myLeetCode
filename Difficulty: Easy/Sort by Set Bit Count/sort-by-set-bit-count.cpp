class Solution {
  public:
    int countSetBits(int n){
        int count=0;
        while(n>0){
            if(n&1==1) count++;
            n=n>>1;
        }
        return count;
    }
    vector<int> sortBySetBitCount(vector<int>& arr) {
        // Jai Shri Ram
        // BF
        vector<pair<int,int>>vp;
        for(int i=0;i <arr.size(); i++){
            int setBits = countSetBits(arr[i]);
            vp.push_back({setBits, i});
        }
        
        
        sort(begin(vp), end(vp),[](auto a, auto b){
            if(a.first==b.first){
                return a.second < b.second;
            }
            return a.first > b.first;
        });
        
        vector<int>ans;
        for(auto &p:vp){
            ans.push_back(arr[p.second]);
        }
        return ans;
    }
};