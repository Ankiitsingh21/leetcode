class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char,int> mpp;
        for(int i=0;i<s.size();i++){
            mpp[s[i]]++;
        }

        priority_queue<pair<char,int>> pq;

        for(auto &it:mpp){
            pq.push({it.first,it.second});
        }

        // while(!pq.empty()){
        //     cout<<pq.top().first<<" ";
        //     pq.pop();
        // }

        int repeat=0;
        string ans="";
        // return ans;
        while(!pq.empty()){
            auto [c,cnt]=pq.top();
            pq.pop();
            if(!ans.empty() && ans.back()==c){
                repeat++;
            }
            if(!ans.empty() && ans.back()!=c){
                repeat=0;
            }

            if(repeat>=repeatLimit){
                if(pq.empty()) break;
                auto[cc,cntt]=pq.top();
                pq.pop();
                cntt--;
                ans+=cc;
                if(cntt>0){
                    pq.push({cc,cntt});
                }
                repeat=0;
            }

            cnt--;
            ans+=c;
            if(cnt>0){
                pq.push({c,cnt});
            }
        }
        return ans;
    }
};