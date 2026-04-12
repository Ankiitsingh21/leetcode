class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),[](auto &a,auto &b){
            if(a[0]==b[0]){
                return a[1]>b[1];
            }
            return a[0]<b[0];
        });
        // vector<vector<int>> ans;
        pair<int,int> pq;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(cnt==0 ||  intervals[i][1]> pq.second){
                // ans.push_back(intervals[i]);
                cnt++;
                pq={intervals[i][0],intervals[i][1]};
            }
        }
        return cnt;
    }
};