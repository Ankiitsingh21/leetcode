class Solution {
public:
    int earliestFinishTime(vector<int>& ls, vector<int>& ld, vector<int>& ws, vector<int>& wd) {
        int ans=INT_MAX;
        for(int i=0;i<ls.size();i++){
            for(int j=0;j<wd.size();j++){
                int f1 = ls[i] + ld[i];
                int f2 = max(f1, ws[j]) + wd[j];
                ans = min(ans, f2);
                // water then land
                f1 = ws[j] + wd[j];
                f2 = max(f1, ls[i]) + ld[i];
                ans = min(ans, f2);
            }
        }
        return ans;
    }
};