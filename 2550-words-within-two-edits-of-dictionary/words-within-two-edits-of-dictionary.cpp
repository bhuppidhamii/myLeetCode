class Solution {
public:
    int calculateHammingDist(string &query, string &word){
        int dist=0;
        for(int i=0; i<word.size(); i++){
            if(query[i]!=word[i]) dist++;
        }
        return dist;
    }
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string>ans;

        for(auto &q:queries){
            bool isDone = false;
            for(auto &w:dictionary){
                int hamDist = calculateHammingDist(q,w);
                if(hamDist <= 2 && isDone==false){
                    isDone=true;
                    ans.push_back(q);
                }
                // if(isDone==false) break;
            }
        }
        return ans;
    }
};