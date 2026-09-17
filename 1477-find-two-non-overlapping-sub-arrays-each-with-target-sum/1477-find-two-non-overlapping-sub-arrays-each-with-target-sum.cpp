class Solution {
public:
    int minSumOfLengths(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> arr(n,INT_MAX);
        int shortest_length=INT_MAX,ans=INT_MAX,sum=0;
        int l=0,r=0;
        while(r<n){
            sum+=nums[r];
            while(sum>target){
                sum-=nums[l];
                l++;
            }
            if(sum==target){
                int length=r-l+1;
                if(l>0 && arr[l-1]!=INT_MAX){
                    ans=min(ans,length+arr[l-1]);
                }
                shortest_length=min(shortest_length,length);
            }
            arr[r]=shortest_length;
            r++;
        }
        return ans==INT_MAX?-1:ans;
    }
};