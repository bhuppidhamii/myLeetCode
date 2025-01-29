class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        vector<vector<int>> grid(n,vector<int>(n,0));
        int i=0,j=0;
        for(auto &c:commands){
            if(c=="RIGHT"){
                j++;
            }else if(c=="LEFT"){
                j--;
            }else if(c=="UP"){
                i--;
            }else {
                i++;
            }
        }
        return (i*n)+j;
    }
};