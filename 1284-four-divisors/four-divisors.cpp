class Solution {
public:
    vector<int>countDivisors(int n){
        int sum=0, count=0;
        for(int i=1; i<=sqrt(n); i++){
            if(n%i == 0){
                // cout<<i<<" ";
                if(i==n/i){
                    count+=1;
                }else{
                    count+=2;
                }
                sum+=(i);
                sum+=(n/i);
            }
        }
        cout<<sum<<" "<<count<<"\n";
        return {sum,count};
    }
    int sumFourDivisors(vector<int>& nums) {
        int totalSum=0;
        for(auto &n:nums){
            vector<int> v = countDivisors(n);
            if(v[1] == 4){
                totalSum+=v[0];
            }
        }
        return totalSum;
    }
};