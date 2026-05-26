class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](const auto &a,const auto &b){
            return a[1]<b[1];
        });
        int n=intervals.size();
        int end=intervals[0][1];
        int cnt=1;
        for(int i=0;i<intervals.size();i++){
            if(intervals[i][0]>=end){
                cnt++;
                end=intervals[i][1];
            }
        }
        return n-cnt;
    }
};