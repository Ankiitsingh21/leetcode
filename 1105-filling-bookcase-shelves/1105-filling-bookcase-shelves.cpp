class Solution {
    int solve(vector<vector<int>> &arr,int swidth,int index,vector<int>&dp){
        if(index==arr.size()){
            return 0;
        }

        if(dp[index]!=-1) return dp[index];
        int curr_width=swidth;
        int max_height=0;
        int res=INT_MAX;
        for(int j=index;j<arr.size();j++){
            int width=arr[j][0];
            int height=arr[j][1];
            if(curr_width<width){
                break;
            }

            curr_width-=width;
            max_height=max(max_height,height);
            res=min(res,(solve(arr,swidth,j+1,dp)+max_height));
        }

        return dp[index]=res;
    }
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        vector<int> dp(books.size(),-1);
        return solve(books,shelfWidth,0,dp);
    }
};