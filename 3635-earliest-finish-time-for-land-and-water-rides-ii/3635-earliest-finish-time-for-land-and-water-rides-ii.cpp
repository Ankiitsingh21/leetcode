class Solution {
public:
    int earliestFinishTime(vector<int>& ls, vector<int>& ld, vector<int>& ws,
                           vector<int>& wd) {
        int miniL = INT_MAX;
        int miniW = INT_MAX;
        for (int i = 0; i < ls.size(); i++) {
            miniL = min(miniL, ls[i] + ld[i]);
        }
        for (int i = 0; i < ws.size(); i++) {
            miniW = min(miniW, ws[i] + wd[i]);
        }
        int ans = INT_MAX;
        // land -> water;
        for (int i = 0; i < ws.size(); i++) {
            int fi = max(miniL, ws[i]) + wd[i];
            ans=min(ans,fi);
        }
        for (int i = 0; i < ls.size(); i++) {
            int fi = max(miniW, ls[i]) + ld[i];
            ans=min(ans,fi);
        }
        return ans;
    }
};