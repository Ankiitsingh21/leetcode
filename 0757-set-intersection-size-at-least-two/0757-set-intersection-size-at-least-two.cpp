class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](const auto &a,const auto &b){
            if(a[1]==b[1]){
                return a[0]>b[0];
            }
            return a[1]<b[1];
        });
        int ans=0;
        int p1=-1,p2=-1;
        for(int i=0;i<intervals.size();i++){
            int left=intervals[i][0];
            int right=intervals[i][1];
            if(p2<left){
                ans+=2;
                p1=right-1;
                p2=right;
            }else if(p1<left){
                ans+=1;
                p1=p2;
                p2=right;
            }
        }
        return ans;
    }
};