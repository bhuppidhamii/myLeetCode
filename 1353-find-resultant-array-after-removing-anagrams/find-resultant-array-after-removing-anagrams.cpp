class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int n=words.size();
        vector<string>ans;
        
        string str=words[0];
        ans.push_back(str);
        sort(str.begin(), str.end());

        for(int i=1;i<n;i++){
            string str1=words[i];
            sort(str1.begin(), str1.end());

            if(str1 != str){
                ans.push_back(words[i]);
                str=str1;
            }
        }
        return ans;
    }
};