class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        // Jai Shri Ram
        map<int,int>mp;
        int N=arr.size();
        int count =0, i=0;
        for(int j=0; j<N; j++){
            mp[arr[j]]++;
            
            while(i<N && mp.size() > k){
                mp[arr[i]]--;
                if(mp[arr[i]] == 0){
                    mp.erase(arr[i]);
                }
                i++;
            }
            
            count+=(j-i+1);
        }
        return count;
    }
};