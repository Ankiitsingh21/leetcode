class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(),
             [&](const auto& a, const auto& b) {
                 if (a[0] == b[0]) {
                     return a[1] > b[1];
                 }
                 return a[0] < b[0];
             });
        int last = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (cnt == 0 || intervals[i][1] > last) {
                cnt++;
                last = intervals[i][1];
            }
        }
        return cnt;
    }
};