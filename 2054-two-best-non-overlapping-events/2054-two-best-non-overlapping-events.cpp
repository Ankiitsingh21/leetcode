class Solution {
    int BinarySearch(int index,vector<vector<int>>& events){
        int low=index+1,high=events.size()-1,next=events.size();
        while(low<=high){
            int mid=low+(high-low)/2;
            if(events[mid][0]>events[index][1]){
                next=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return next;
    }
    int solve(int index,vector<vector<int>>& events,int cnt,vector<vector<int>> &dp){
        if(index==events.size()) return 0;
        if(cnt==2) return 0;
        if(dp[index][cnt]!=-1) return dp[index][cnt];

        //skip
        int skip=solve(index+1,events,cnt,dp);

        //take
        int nextIndex=BinarySearch(index,events);


        return dp[index][cnt]= max(skip,events[index][2]+solve(nextIndex,events,cnt+1,dp));
    }
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        vector<vector<int>> dp(events.size(),vector<int> (2,-1));
        return solve(0,events,0,dp);
    }
};