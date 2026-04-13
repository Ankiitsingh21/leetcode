class Solution {
public:
    string reorganizeString(string s) {
        map<char,int> mpp;
        for(auto c:s){
            mpp[c]++;
        }
        priority_queue<pair<int,char>> pq;
        // queue<pair<int,pair<int,char>>> q;
        for(auto it:mpp){
            pq.push({it.second,it.first});
        }
        // int time=0;
        string ans="";
         pair<int,char> prev ;
        while(!pq.empty()){
           auto [cnt,c]=pq.top();
           pq.pop();
           ans+=c;
           cnt--;
           
           if(prev.first>0) {
            pq.push(prev);
           }
           prev={cnt,c};
        }
        if(ans.size() != s.size()) return "";
        return ans;
    }
};