class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        sort(points.begin(),points.end(),[](const auto &a,const auto &b){
            return a[1]<b[1];
        });

        int cnt=1;
        int groupEnd=points[0][1];
        for(int i=1;i<n;i++){
            if(points[i][0]>groupEnd){
                cnt++;
                groupEnd=points[i][1];
            }
        }
        return cnt;
    }
};