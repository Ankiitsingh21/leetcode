class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int> prefix(n,1);
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]){
                prefix[i]=prefix[i-1]+1;
            }
        }
        int sum=prefix[n-1];
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1] && prefix[i]<=prefix[i+1]){
                prefix[i]=prefix[i+1]+1;
            }
            sum+=prefix[i];
        }
        return sum;
    }
};