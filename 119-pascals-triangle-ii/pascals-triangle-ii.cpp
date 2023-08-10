class Solution {
private:
    long findNCR(int N, int R){
        long res=1;
        for(int i=0;i<R;i++){
            res = res * (N-i);
            res = res / (i+1);
        }
        return res;
    }
public:
    vector<int> getRow(int RowNum) {
        vector<int>ans;
        for(int col=0;col<=RowNum;col++){
            ans.push_back(findNCR(RowNum,col));
        }
        return ans;
    }
};