class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        long long ans=LLONG_MIN;
        for(int i=1;i+1<m;++i){
            for(int j=1;j+1<n;++j){
                ans=max(ans,(long long) grid[i][j]);
            }
        }
        for(int i=0;i<m;++i){
            vector<long long> pref(n+1,0);
            for(int j=0;j<n;++j){
                pref[j+1]=pref[j]+grid[i][j];
            }
            long long minPref=0;
            for(int r=2;r<=n;r++){
                minPref=min(minPref,pref[r-2]);
                ans=max(ans,pref[r]-minPref);
            }
        }
        for(int j=0;j<n;++j){
            vector<long long> pref(m+1,0);
            for(int i=0;i<m;i++){
                pref[i+1]=pref[i]+grid[i][j];
            }
            long long minPref=0;
            for(int r=2;r<=m;++r){
                minPref=min(minPref,pref[r-2]);
                ans=max(ans,pref[r]-minPref);
            }
        }
        return (int)ans;
    }
};