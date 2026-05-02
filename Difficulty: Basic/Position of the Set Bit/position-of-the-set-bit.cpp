class Solution {
  public:
    bool checkPowerof2(int n){
        while(n%2==0){
            n/=2;
        }
        return n==1;
    }
    int findPosition(int n) {
        // Jai Shri Ram
        
        // check if it is a power of 2
        if(checkPowerof2(n)==true){
            // count the postion
            int pos = 1;
            while(n%2==0){
                pos++;
                n/=2;
            }
            return pos;
        }
        return -1;
    }
};