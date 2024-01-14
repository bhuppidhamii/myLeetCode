class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int l1 = word1.length(), l2 = word2.length();
        if (l1 != l2) return false;

        vector<int>freq1(26,0);
        for(auto ch:word1){
            int idx=ch-'a';
            freq1[idx]++;
        }

        vector<int>freq2(26,0);
        for(auto ch:word2){
            int idx=ch-'a';
            freq2[idx]++;
        }

        for(int i=0;i<26;i++){
            if(!((freq1[i]!=0 && freq2[i]!=0) || (freq1[i]==0 && freq2[i]==0))){
                return false;
            }
        }
        
        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());

        return freq1==freq2;
    }
};