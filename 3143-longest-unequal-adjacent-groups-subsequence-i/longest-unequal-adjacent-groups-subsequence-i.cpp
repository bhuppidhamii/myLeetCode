class Solution {
public:
    int N;
    vector<string> solve(int i, vector<string>& words, vector<int>& groups, vector<string>&temp, vector<int>&gTemp){
        if(i >= N){
            return temp;
        }

        // take 
        if( groups[i] != gTemp.back()){
            temp.push_back(words[i]);
            gTemp.push_back(groups[i]);

            return solve(i+1, words, groups, temp, gTemp);
        }

        // not take
        return solve(i+1, words, groups, temp, gTemp);

        
    }
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        N=words.size();
        int maxLen=-1;
        vector<string>ans;
        for(int i=0; i<N; i++){
            vector<string>temp;
            temp.push_back(words[i]);
            vector<int>gTemp;
            gTemp.push_back(groups[i]);
            vector<string>v=solve(i+1, words, groups, temp, gTemp);
            if((int)v.size() > maxLen){
                maxLen=(int)v.size();
                ans=v;
            }
            temp.erase(temp.begin());
            gTemp.erase(gTemp.begin());
        }
        return ans;
    }
};