class Solution {
public:
    bool check(string &str){
        string s = str;
        sort(begin(s), end(s));
        return s == str;
    }
    int minDeletionSize(vector<string>& strs) {
        int l=strs[0].size(); // all strings are of same lenght => l;
        vector<string>arr(l, "");
        for(auto &s:strs){
            int n = s.size();
            for(int i=0; i<n; i++){
                arr[i]+=s[i];
            }
        }
        int count = 0;
        for(auto &a:arr){
            if(!check(a))count++;
        }
        return count;
    }
};