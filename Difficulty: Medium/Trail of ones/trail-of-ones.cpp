class Solution {
  public:
    int countConsec(int n) {
        // Jai Shri Ram
        if(n == 2){
            return 1;
        }
        int first = 0, second = 1, third;
        int result = 1;
        
        for(int i=3; i<=n; i++){
            third = first + second;
            result = result * 2 + third;
            first = second;
            second = third;
        }
        return result;
    }
};