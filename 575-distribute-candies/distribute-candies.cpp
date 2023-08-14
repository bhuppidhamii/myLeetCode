class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        map<int,int>m;
        int n=candyType.size();
        for(auto i:candyType){
            m[i]++;
        }
        if(m.size()<=n/2){
            return m.size();
        }else{
            return n/2;
        }

    }
};