class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        for(int i=n-1;i>=0;i--){
            if(digits[i]<9){
                digits[i]++;
                return digits;
            }else{
                digits[i]=0;
            }
        }
        
        //if all digits are 9,9,9,9.....
        vector<int>ans(n+1); // all pos will be zeros
        ans[0]=1; //first digit will be 1 ( 99+1= 100)
        return ans;

    }
};