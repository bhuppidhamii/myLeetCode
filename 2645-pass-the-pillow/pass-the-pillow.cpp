class Solution {
public:
    int passThePillow(int n, int time) {
        int fullRound=time/(n-1);
        int left=time%(n-1);

        if(fullRound%2==0){
          return left+1;
        }
        return n-left;
    }
};