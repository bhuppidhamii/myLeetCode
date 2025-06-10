class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int>mp;
        for(auto &ch:s){
            mp[ch]++;
        }
        int maxOdd=-1;
        int minEven=INT_MAX;
        for(auto &i:mp){
            if(i.second%2==0){
                minEven=min(minEven, i.second);
            }else{
                maxOdd=max(maxOdd, i.second);
            }
        }
        return maxOdd-minEven;
    }
};