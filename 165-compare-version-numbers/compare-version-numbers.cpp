class Solution {
public:
    int compareVersion(string version1, string version2) {
       int L1 = version1.size(), i = 0;
       int L2 = version2.size(), j = 0;

       while(i < L1 || j < L2){
        
        // gather all elements till '.'
        string s1 = "";
        while(i < L1 && version1[i] != '.'){
            s1+=version1[i];
            i++;
        }
        cout<<i<<" ";
        int n1 = (s1.size()==0) ? 0 : stoi(s1);
        cout<<n1<<" \n";
        
        string s2 = "";
        while(j < L2 && version2[j] != '.'){
            s2+=version2[j];
            j++;
        }
        cout<<j<<" ";

        int n2 = (s2.size()==0) ? 0 : stoi(s2);
        cout<<n2<<" \n";

        // compare them
        if(n1 < n2) return -1;
        if(n1 > n2) return 1;

        // cout<<i<<" "<<j<<"\n";
        i++,j++;
       }
       return 0;
    }
};