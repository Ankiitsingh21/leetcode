class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),[](auto &a,auto &b){
            return a[1]<b[1];
        });
        // vector<vector<int>> ans;
        int groupEnd=intervals[0][1];
        int count=1;
        for(int i=1;i<n;i++){
           if( intervals[i][0]>groupEnd){
            // ans.push_back(intervals[i]);
            count++;
            groupEnd=intervals[i][1];
            // cout<<intervals[i][0]<<" "<<ans.back()[1]<<" ";
           }
        }
        return count;
    }
};