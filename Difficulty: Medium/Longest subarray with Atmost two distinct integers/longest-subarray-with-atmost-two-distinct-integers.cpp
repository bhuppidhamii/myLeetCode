class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // Jai Shri Ram
        int N = arr.size(), i = 0;
        int max_len = -1;
        
        map<int,int>mp;
        for(int j=0; j<N; j++){
            mp[arr[j]]++;
            
            while(i < N && mp.size() > 2){
                mp[arr[i]]--;
                if(mp[arr[i]] == 0){
                    mp.erase(arr[i]);
                }
                i++;
            }
            
            int len = j-i+1;
            max_len = max(max_len, len);
        }
        return max_len;
    }
};