class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<pair<int,int>> eve;
        for(int i=0;i<logs.size();i++){
            eve.push_back({logs[i][0],1});
            eve.push_back({logs[i][1],-1});
        }
        sort(eve.begin(),eve.end());
        int curr=0;
        int maxi=0;
        int yr=0;
        for(auto &e:eve){
            curr+=e.second;
            if(curr>maxi){
                maxi=curr;
                yr=e.first;
            }
        }
        return yr;
    }
};