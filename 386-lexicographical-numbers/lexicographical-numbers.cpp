class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string>vs;
        for(int i=1; i<=n; i++){
            vs.push_back(to_string(i));
        }

        sort(begin(vs), end(vs));
        vector<int>ans;
        for(auto &s:vs){
            ans.push_back(stoi(s));
        }
        return ans;
    }
};