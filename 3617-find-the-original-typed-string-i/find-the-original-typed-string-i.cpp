class Solution {
public:
    int possibleStringCount(string s) {
        int count=0, N=s.size();
        int ans=0;
        int i=0;
        while(i < N){
            int j=i+1;
            int count=0;
            while(j < N && s[j] == s[j-1]){
                count++;
                j++;
            }
            ans+=count;
            i=j;
        }
        return ans+1;
    }
};