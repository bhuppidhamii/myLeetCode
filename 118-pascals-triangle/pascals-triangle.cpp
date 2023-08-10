class Solution {
private:
    int findNCR(int N, int R){
        int res=1;
        for(int i=0;i<R;i++){
            res = res * (N-i);
            res = res / (i+1);
        }
        return res;
    }
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=0;i < numRows;i++){
            vector<int>temp;
            for(int j=0; j <= i; j++){
                temp.push_back(findNCR(i,j));
            }
            ans.push_back(temp);
        }
        return ans;
    }
};