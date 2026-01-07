class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // Jai Shri Ram
        map<int,int>mp;
        for(int i=0; i<k-1; i++){
            mp[arr[i]]++;
        }
        
        vector<int>result;
        int n=arr.size(), i=0;
        for(int j=k-1; j<n; j++){
            mp[arr[j]]++;
            result.push_back((int)mp.size());
            
            mp[arr[i]]--;
            if(mp[arr[i]]==0) mp.erase(arr[i]);
            i++;
        }
        return result;
    }
};