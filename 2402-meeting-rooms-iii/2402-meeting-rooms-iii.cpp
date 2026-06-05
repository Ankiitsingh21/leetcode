class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        priority_queue<int,vector<int>,greater<int>> fr;
        for (int i = 0; i < n; i++) {
            fr.push(i);
        }
        map<int, int> mpp;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            br;
        for (int i = 0; i < meetings.size(); i++) {
            int start = meetings[i][0];
            int end = meetings[i][1];
            while (!br.empty() && br.top().first <= start) {
                fr.push(br.top().second);
                br.pop();
            }
            if (!fr.empty()) {
                mpp[fr.top()]++;
                br.push({end, fr.top()});
                fr.pop();
            } else {
                int nearestR = br.top().second;
                mpp[nearestR]++;
                long long diff = br.top().first - start;
                br.pop();
                br.push({(long long) end + diff, nearestR});
            }
        }
        int ans = INT_MIN;
        int maxi = INT_MIN;
        for (auto it : mpp) {
            // cout<<it.first<<" "<<it.second<<" "<<endl;
            if (it.second > maxi) {
                ans = it.first;
                maxi = it.second;
            }
            // ans=max(ans,it.second);
        }
        return ans;
    }
};