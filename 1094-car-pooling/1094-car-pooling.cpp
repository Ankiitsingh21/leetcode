class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<pair<int,int>> eve;
        for(int i=0;i<trips.size();i++){
            int c=trips[i][0];
            int u=trips[i][1];
            int v=trips[i][2];
            eve.push_back({u,c});
            eve.push_back({v,-c});
        }
        sort(eve.begin(),eve.end());
        int curr=0;
        for(int i=0;i<eve.size();i++){
            curr+=eve[i].second;
            if(curr>capacity) return false;
        }
        return true;
    }
};