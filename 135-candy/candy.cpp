class Solution {
public:
    int candy(vector<int>& rating) {
        int N=rating.size();
        vector<int>v(N, 1);

        // L->R
        for(int i=1; i<N; i++){
            if(rating[i] > rating[i-1]){
                v[i]=v[i-1]+1;
            }
        }

        // R->L
        vector<int>v2(N,1);
        for(int i=N-2; i>=0; i--){
            if(rating[i] > rating[i+1]){
                v2[i]=v2[i+1]+1;
            }
        }
        vector<int>ans(N, 0);
        for(int i=0; i<N; i++){
            ans[i]=max(v[i], v2[i]);
        }
        int sum=accumulate(begin(ans), end(ans), 0);
        return sum;
    }
};