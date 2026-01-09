class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        // Jai Shri Ram
        
        map<int,int>mp;
        int n=arr.size(), i=0;
        int ans = 0;
        for(int j=0; j<n; j++){
            mp[arr[j]]++;
            
            while(i<n && mp.size() > k){
                mp[arr[i]]--;
                if(mp[arr[i]]==0)mp.erase(arr[i]);
                i++;
            }
            int count = j-i+1;
            ans+=count;
        }
        return ans;
    }
};