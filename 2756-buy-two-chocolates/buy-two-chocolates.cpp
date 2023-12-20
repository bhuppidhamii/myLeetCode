class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int mini1=INT_MAX, mini2=0;
        for(auto &p:prices){
            if(p < mini1){
                mini2 = mini1;
                mini1 = p;
            }else{
                mini2 = min(p, mini2);
            }
        }
        int sum = mini1 + mini2;
        if(sum <= money){
            return money-sum;
        }else{
            return money;
        }
    }
};