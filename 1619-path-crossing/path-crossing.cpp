class Solution {
public:
    bool isPathCrossing(string path) {
        map< pair<int,int>, int> m;
        int i=0, j=0;
        m[{i,j}]++;
        for(auto &d:path){
            if(d == 'N'){
                j++;
            }else if(d == 'S'){
                j--;
            }else if(d == 'E'){
                i++;
            }else{
                i--;
            }

            if(m.find({i,j}) == m.end()){
                m[{i,j}]++;
            }else{
                return true;
            }
        }
        return false;
    }
};