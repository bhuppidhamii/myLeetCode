class Solution {
public:
    bool check(string &word1, string &word2){
        map<char, int>mp1;
        for(auto &ch:word1){
            mp1[ch]++;
        }

        map<char, int>mp2;
        for(auto &ch:word2){
            mp2[ch]++;
        }

        return mp1==mp2;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        // Jai Shri Ram
        int N = words.size();
        int i=0,j=0;
        vector<string>ans;
        while(i < N){
            int j=i+1;
            while(j<N && check(words[i], words[j])==true){
                j++;
            }
            ans.push_back(words[i]);
            i=j;
        }
        return ans;
    }
};