class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        // Jai Shri Ram
        // 2 - pointer approach
        int p=0, t=0, N=arr.size();
        int count=0;
        while(p<N && t<N){
            // move p to police-man
            while(p < N && arr[p] != 'P'){
                p++;
            }
            
            // move t to thief
            while(t < N && arr[t] != 'T'){
                t++;
            }
            
            if(p<N && t< N && abs(t-p) <= k){
                count++;
                // cout<<p<<" "<<t<<"\n";
                p++, t++;
                                    // eaual but diff > k
            }else if(t<N && t < p){ // if thief is behind police
                t++;
            }else if(p<N && p < t){ // if police is behid thief
                p++;
            }
        }
        return count;
    }
};