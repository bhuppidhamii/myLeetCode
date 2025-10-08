class Solution {
public:
    int binarySearch(vector<int>& potions, long long target){
        int low = 0;
        int high = potions.size()-1;

        int ans = -1;
        while(low <= high){
            int mid = low + (high-low)/2;

            if(potions[mid] >= target){
                ans = mid; // this could be a potential ans
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions,
        long long success) {
        // BF
        int n = spells.size();
        int m = potions.size();

        sort(begin(potions), end(potions));
        vector<int>result;
        for(auto &s:spells){
            // a*b>=success -> b >= success/a
            double a = s;
            int count = 0;
                long long b = ceil(success/a);
                cout<<b;
                
                // find 1st idx of element which is greater than b in potions
                int idx = binarySearch(potions, b);
                // cout<<idx<<"\n";
                if(idx == -1){
                    result.push_back(0);
                }else{
                    // then, add m-idx + count;
                    result.push_back(m-idx);
                }
        }
        // cout<<binarySearch(potions, 5);
        return result;
    }
};