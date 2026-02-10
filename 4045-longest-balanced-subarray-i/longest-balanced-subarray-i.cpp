class Solution {
public:
    int longestBalanced(vector<int>& arr) {
        int n = arr.size();
        int maxLen = 0;
        for(int i=0; i<n; i++){
            unordered_set<int>odd,even;
            for(int j=i; j<n; j++){
                if(arr[j]%2==0){
                    even.insert(arr[j]);
                }else{
                    odd.insert(arr[j]);
                }
                if(odd.size() == even.size()){
                    maxLen = max(maxLen, j-i+1);
                }
            }
        }
        return maxLen;
    }
};