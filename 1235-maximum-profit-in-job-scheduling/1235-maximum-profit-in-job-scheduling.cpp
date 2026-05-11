class Solution {
    int binarySearch(int index, vector<vector<int>>& events) {
        int low = index + 1;
        int high = events.size() - 1;
        int next = events.size();
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (events[mid][0] >= events[index][1]) {
                next = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return next;
    }
    int solve(int index, vector<vector<int>>& events, int k,
              vector<int>& dp) {
        if (index == events.size())
            return 0;
        if (k == 0)
            return 0;
        if (dp[index] != -1)
            return dp[index];
        // skip
        int skippi = solve(index + 1, events, k, dp);

        // fill
        int nextIndex = binarySearch(index, events);
        int fill = events[index][2] + solve(nextIndex, events, k - 1, dp);
        return dp[index]= max(fill, skippi);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        // sort(events.begin(),events.end(),[](const auto &a,const auto & b){
        //     return a[2]>b[2];
        // });
        sort(events.begin(), events.end());
        // vector<vector<int>> dp(events.size(), vector<int>(k + 1, -1));
        // int ans = INT_MIN;
        // for (int i = 0; i < n; i++) {
        //     ans = max(ans, solve(i, events, k, dp));
        // }
        vector<int> dp(events.size(),-1);
        return solve(0,events,k,dp);
    }

public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime,
                      vector<int>& profit) {
        int n = profit.size();

        vector<vector<int>> events(n, vector<int>(3));

        for (int i = 0; i < n; i++) {
            events[i][0] = startTime[i];
            events[i][1] = endTime[i];
            events[i][2] = profit[i];
        }
        return maxValue(events, n);
    }
};