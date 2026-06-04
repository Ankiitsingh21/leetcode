class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int> prefix(n,1);
        prefix[0]=1;
        for(int i=1;i<prefix.size();i++){
            if(ratings[i]>ratings[i-1]){
                prefix[i]=prefix[i-1]+1;
            }
        }
        int sum=0;
        for(int i=prefix.size()-2;i>=0;i--){
            if(ratings[i]>ratings[i+1] && prefix[i]<=prefix[i+1]){
                prefix[i]=prefix[i+1]+1;
            }
            sum+=prefix[i];
        }
        // vector<int> suffix(ratings.size(),1);
        // for(int i=0;i<prefix.size();i++){
        //     sum+=prefix[i];
        //     // cout<<prefix[i]<<" ";
        // }
        return sum+prefix[n-1];
    }
};