class Solution {
  public:
    int minSoldiers(vector<int>& arr, int k) {
        // Jai Shri Ram
        int N = arr.size();
        int req = N/2;
        
        int present = 0;
        vector<int>v;
        for(auto &i:arr){
            if(i%k == 0){
                present++;
                
            }else{
                int d = i/k;
                d++;
                v.push_back(k*d - i);
            }
        }
        if(present > req) return 0;
        
        // cout<<" req "<<req<<"\n";
        // cout<<" present "<<present<<"\n";
        
        sort(v.begin(), v.end());
        for(auto &i:v){
            // cout<<i<<" ";
        }
        // cout<<"\n";
        int ans = 0;
        for(auto &i:v){
            ans+=i;
            present++;
            if(present >= req) break;
        }
        return ans;
    }
};