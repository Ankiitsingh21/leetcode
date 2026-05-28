class Solution {
    int helper(vector<int> &arr, int mid, int k) {
    int bouquets = 0, flowers = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] <= mid) {
            flowers++;
            if (flowers == k) {
                bouquets++;
                flowers = 0;  // reset streak after making 1 bouquet
            }
        } else {
            flowers = 0;  // break streak
        }
    }
    return bouquets;
}

public:
    int minDays(vector<int>& arr, int m, int k) {
        int maxi=INT_MIN,mini=INT_MAX;
        for(int i=0;i<arr.size();i++){
            maxi=max(maxi,arr[i]);
            mini=min(mini,arr[i]);
        }
        int low=mini,high=maxi;
        int ans=INT_MAX;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(helper(arr,mid,k)>=m){
                ans=min(ans,mid);
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return (ans==INT_MAX)?-1:ans;
    }
};