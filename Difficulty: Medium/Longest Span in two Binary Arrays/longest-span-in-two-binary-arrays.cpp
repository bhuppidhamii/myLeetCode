class Solution {
  public:
    int longestCommonSum(vector<int> &a1, vector<int> &a2) {
        // Code here.
        int N = a1.size();
        vector<int>diff(N, 0);
        for(int i=0; i<N; i++){
            diff[i] = a1[i] - a2[i];
        }
        
        // longest subarray with sum 0
        unordered_map<int, int>mp;
        mp[0] = -1; // edge case 
        int currSum = 0;
        int maxLen = 0;
        
        for(int j=0; j<N; j++){
            currSum+=diff[j];
            if(mp.find(currSum) != mp.end()){ // kya phle dekha h kabhi?
                int len =(j - mp[currSum]);
                if(len > maxLen){
                    maxLen = len;
                }
            }else{
                mp[currSum] = j;
            }
        }
        return maxLen;
    }
};