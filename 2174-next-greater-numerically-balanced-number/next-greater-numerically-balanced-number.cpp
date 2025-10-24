class Solution {
public:
    bool checkBeautiful(int n){
        vector<int>freq(10,0);
        while(n > 0){
            int rem = n%10;
            freq[rem]++;
            n/=10;
        }
        for(int i=0; i<10; i++){
            if(freq[i]!=0){
                if(i!=freq[i]) return false;
            }
        }
        return true;
    }
    int nextBeautifulNumber(int n) {
        for(int i=n+1; i<=1224444; i++){
            if(checkBeautiful(i) == true){
                return i;
            }
        }
        return -1;
    }
}; 