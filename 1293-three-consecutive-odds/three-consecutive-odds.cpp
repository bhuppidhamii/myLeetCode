class Solution {
public:
    bool isOdd(int n){
        return n%2 == 1 ? true : false;
    }
    bool threeConsecutiveOdds(vector<int>& arr) {
        int N=arr.size();
        for(int i=0; i<= N-3; i++){
            if(isOdd(arr[i]) && isOdd(arr[i+1]) && isOdd(arr[i+2])){
                return true;
            }
        }
        return false;
    }
};