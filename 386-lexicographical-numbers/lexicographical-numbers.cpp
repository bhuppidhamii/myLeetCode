class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string>lexi;

        for(int i=1;i<=n;i++){
            lexi.push_back(to_string(i));
        }
        sort(lexi.begin(), lexi.end());

        vector<int>ans;
        for(auto i:lexi){
            ans.push_back(stoi(i));
        }
        
        return ans;
    }
};