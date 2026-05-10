class Solution {
    int binarySearch(int index,vector<vector<int>>& rides){
        int low=index+1;
        int high=rides.size()-1;
        int next=rides.size();
        while(low<=high){
            int mid=low+(high-low)/2;
            if(rides[mid][0]>=rides[index][1]){
                next=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return next;
    }
    long long solve(int index,vector<vector<int>>& rides,vector<long long> &dp ){
        if(index==rides.size()) return 0;

        if(dp[index]!=-1) return dp[index];

        //skippi
        long long skippi=solve(index+1,rides,dp);


        long long best=(rides[index][1]-rides[index][0])+rides[index][2];
        int nextIndex=binarySearch(index,rides);
        // long long best = p;
        // //i have to choose where i should go okey
        // for(int i=index+1;i<rides.size();i++){
        //     if( rides[index][1]<=rides[i][0]){

        //         best=max(best,p+solve(i,rides,dp));
        //     }
        //     // best=
        // }

        return dp[index]= max(skippi,best+solve(nextIndex,rides,dp));
    }
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(rides.begin(), rides.end());
        vector<long long> dp(rides.size(),-1);
        return solve(0,rides,dp);
    }
};