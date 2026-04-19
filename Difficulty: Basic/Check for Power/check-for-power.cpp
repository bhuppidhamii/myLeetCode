class Solution {
  public:
    bool isPower(int x, int y) {
        // Jai Shri Ram
        if(x==1) return false;
        while(y>=x && y%x == 0){
            y=y/x;
        }
        return y==1 ? true: false;
    }
};