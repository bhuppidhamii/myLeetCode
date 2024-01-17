class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int>m1;
        for(auto ch:s){
            m1[ch]++;
        }

        unordered_map<char,int>m2;
        for(auto ch:t){
            m2[ch]++;
        }

        if(m1==m2) return 0;
        int steps = 0;

        for(auto i:m1){
            char ch=i.first;
            int freq=i.second;

            if(m2.find(ch)==m2.end()){
                m2[ch]=freq;
                steps+=freq;
            }else{ // present but freq is not equal
                if(freq!=m2[ch]){
                    int diff=abs(freq-m2[ch]);
                    if(freq>m2[ch]){
                        m2[ch]+=diff;
                    }else{
                        m1[ch]+=diff;
                    }
                    steps+=diff;
                }
            }
        }
        for(auto i:m2){
            char ch=i.first;
            int freq=i.second;
            
            if(m1.find(ch)==m1.end()){
                m1[ch]=freq;
                steps+=freq;
            }else{
                if(freq!=m1[ch]){
                    int diff=abs(freq-m1[ch]);
                        if(freq>m1[ch]){
                            m1[ch]+=diff;
                        }else{
                            m2[ch]+=diff;
                        }
                        steps+=diff;
                    
                }
            }
        }
        return steps;
    }
};