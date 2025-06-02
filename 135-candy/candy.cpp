class Solution {
public:
    int candy(vector<int>& rating) {
        int N=rating.size();
        vector<int>L2R(N, 1);

        // L->R
        for(int i=1; i<N; i++){
            if(rating[i] > rating[i-1]){
                L2R[i]=L2R[i-1]+1;
            }
        }

        // R->L
        vector<int>R2L(N,1);
        for(int i=N-2; i>=0; i--){
            if(rating[i] > rating[i+1]){
                R2L[i]=R2L[i+1]+1;
            }
        }
        
        vector<int>ans(N, 0);
        for(int i=0; i<N; i++){
            ans[i]=max(L2R[i], R2L[i]);
        }
        int sum=accumulate(begin(ans), end(ans), 0);
        return sum;
    }
};