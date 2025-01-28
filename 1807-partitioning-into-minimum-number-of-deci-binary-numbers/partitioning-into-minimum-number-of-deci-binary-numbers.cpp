class Solution {
public:
    int minPartitions(string n) {
        int maxi=1;
        for(auto ch:n){
            int num=ch-'0';
            // cout<<num;
            if(num>maxi){
                maxi=num;
            }
        }
        return maxi;
    }
};