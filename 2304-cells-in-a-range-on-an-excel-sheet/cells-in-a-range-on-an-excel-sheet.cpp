class Solution {
public:
    vector<string> cellsInRange(string s) {
        int l = s.size();
        char start = s[0];
        char end = s[l-2];

        int row = s[l-1]-'0';

        vector<string> ans;
        int itr = (end-'0') - (start-'0') + 1;
        for(int i=0;i < itr;i++){
            for(int i=s[1]-'0';i<=row;i++){
                string temp;
                temp+=start;
                temp+=to_string(i);
                ans.push_back(temp);
            }
            start++;
        }
        return ans;
    }
};