class Solution {
public:
    string reorganizeString(string s) {
        int n=s.length();
        map<char,int>m;
        for(auto ch:s){
            m[ch]++;
        }

        priority_queue< pair<int,char>> pq;
        for(auto i:m){
            if(i.second > (n+1)/2){
                return "";
            }
            pq.push({i.second,i.first});
        }

        string ans="";

        while(pq.size()>=2){
            pair<int,char>p1=pq.top();
            pq.pop();

            pair<int,char>p2=pq.top();
            pq.pop();

            ans+=p1.second;
            ans+=p2.second;

            if(p1.first > 1){
                pq.push({p1.first-1, p1.second});
            }
            if(p2.first > 1){
                pq.push({p2.first-1, p2.second});
            }
        }
        if(pq.size()==1){
            ans+=pq.top().second;
        }
        return ans;
    }
};