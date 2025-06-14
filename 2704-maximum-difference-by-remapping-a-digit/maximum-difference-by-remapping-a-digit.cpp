class Solution {
public:
    void changeMax(string &str, char toChange){
        for(int i=0; i<str.size(); i++){
            if(str[i] == toChange){
                str[i]='9';
            }
        }
    }
    void changeMin(string &str, char toChange2){
        for(int i=0; i<str.size(); i++){
            if(str[i] == toChange2){
                str[i]='0';
            }
        }
    } 
    int minMaxDifference(int num) {
        // Jai Shri Ram
        // find max
        // change the 1st non "9" occurence & its counterparts to "9".
        string str1=to_string(num);
        int N=str1.size();
        char toChange;
        for(int i=0; i<N; i++){
            if(str1[i] != '9'){
                toChange=str1[i];
                break;
            }
        }
        changeMax(str1, toChange);
        int maxi=stoi(str1);
        cout<<maxi<<"\n";

        // find min
        // change the 1st non '0' occurence & its counterparts to '0'
        string str2=to_string(num);
        char toChange2;
        for(int i=0; i<N; i++){
            if(str1[i] != '0'){
                toChange2=str2[i];
                break;
            }
        }
        changeMin(str2, toChange2);
        // cout<<str2;
        int mini=stoi(str2);
        cout<<mini;
        return maxi-mini;
    }
};