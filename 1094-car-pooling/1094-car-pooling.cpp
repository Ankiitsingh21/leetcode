class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<pair<int,int>> event;
        for(int i=0;i<trips.size();i++){
            event.push_back({trips[i][1],trips[i][0]});
            event.push_back({trips[i][2],-trips[i][0]});
        }
        sort(event.begin(),event.end());
        int curr=0;
        for(auto &e:event){
            curr+=e.second;
            if(curr>capacity) return false;
        }
        return true;
    }
};