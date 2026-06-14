class Solution {
    int solve(int index,int swidth,vector<vector<int>> &arr,vector<int> &dp){
        if(index==arr.size()) return 0;
        if(dp[index]!=-1) return dp[index];
        int currW=swidth;
        int maxheight=0;
        int res=INT_MAX;
        for(int i=index;i<arr.size();i++){
            int width=arr[i][0];
            if(width>currW){
                break;
            }
            currW-=width;
            maxheight=max(maxheight,arr[i][1]);
            res=min(res,solve(i+1,swidth,arr,dp)+maxheight);
        }
        return dp[index]= res;
    }
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        vector<int> dp(books.size(),-1);
        return solve(0,shelfWidth,books,dp);
    }
};