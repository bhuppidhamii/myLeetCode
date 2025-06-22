class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        // sort(s.begin(), s.end());
        int N=s.size();
        int i=0;
        int rem=N%k;
        if(rem !=0){
            rem = (k-rem);
        }
        cout<<rem;
        vector<string>ans;
        while(i < N){
            int j=i;
            string temp="";
            while(i<N && i<j+k){
                temp+=s[i];
                i++;
            }
            ans.push_back(temp);
        }
        string last=ans.back();
        ans.pop_back();
        while(rem--){
            last+=fill;
        }
        ans.push_back(last);
        return ans;
    }
};