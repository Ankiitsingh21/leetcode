class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<pair<int, int>> eve;
        for (int i = 0; i < intervals.size(); i++) {
            int s = intervals[i][0];
            int e = intervals[i][1];
            // if(s==e) continue;
            // cout<<s<<' '<<e<<" ";
            eve.push_back({s, 1});
            eve.push_back({e+1, -1});
        }
        // if(eve.size()==0) return ;
        sort(eve.begin(), eve.end());
        int curr = 0;
        int ans = 1;
        for (int i = 0; i < eve.size(); i++) {
            curr += eve[i].second;
            ans = max(ans, curr);
        }
        return ans;
    }
};