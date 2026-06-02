class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int, int>> eve;
        for (int i = 0; i < ranges.size(); i++) {
            // eve.push_back({i-ranges[i],i+ranges[i]});
            int left = i - ranges[i];
            if (left < 0)
                left = 0;
            eve.push_back({left, i + ranges[i]});
        }
        sort(eve.begin(), eve.end(), [](const auto& a, const auto& b) {
            if (a.first == b.first)
                return a.second > b.second;
            return a.first < b.first;
        });

        // for(int i=0;i<eve.size();i++){
        //     cout<<eve[i].first<<" "<<eve[i].second<<" "<<endl;
        // }

        int cnt = 0;
        int end = 0;
        int last = 0;
        for (int i = 0; i < eve.size(); i++) {
            if (eve[i].first > end)
                return -1;
            if (eve[i].first > last) {
                cnt++;
                last = max(last,end);
            }
            end = max(end, eve[i].second);
            if(end>=n) break;
        }
        if(end<n) return -1;
        return cnt+1;
    }
};