class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans=0;
        int maxi=values[0]-1;
        for(int i=1;i<values.size();i++){
            ans=max(ans,values[i]+maxi);
            maxi=max(maxi-1,values[i]-1);
        }
        return ans;
    }
};