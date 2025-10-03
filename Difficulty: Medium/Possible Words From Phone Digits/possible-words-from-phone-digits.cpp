class Solution {
  public:
    vector<string>result;
    void solve(int i, vector<string>&str, string&temp){
        if(temp.size() == str.size()){
            result.push_back(temp);
            // cout<<temp<<" "<<"\n";
            return;
        }
        
        // base case
        if(i >= str.size()) return;
        
            // cout<<str[i]<<"\n";
            for(int j = 0; j < str[i].size(); j++){
                temp+=str[i][j];
                
                solve(i+1, str, temp);
                
                temp.pop_back();
            }

    }
    vector<string> possibleWords(vector<int> &arr) {
        // Jai Shri Ram. 
        
        map<int, string>mp;
        mp[2]="abc";
        mp[3]="def";
        mp[4]="ghi";
        mp[5]="jkl";
        mp[6]="mno";
        mp[7]="pqrs";
        mp[8]="tuv";
        mp[9]="wxyz";
        
        
        vector<string>str;
        for(auto &i:arr){
            if(i==1 || i==0) continue;
            str.push_back(mp[i]);
        }
        // for(auto &s:str){
        //     cout<<s<<" ";
        // }
        string temp = "";
        solve(0, str, temp);
        
        return result;
    }
};