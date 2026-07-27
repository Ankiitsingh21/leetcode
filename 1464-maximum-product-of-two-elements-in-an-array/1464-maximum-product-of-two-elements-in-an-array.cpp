class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi=INT_MIN;
        int secondMax=INT_MIN;
        for(int num:nums){
            if(maxi<=num){
                secondMax=maxi;
                maxi=num;
            }else if(secondMax<=num){
                secondMax=num;
            }
        }
        // cout<<maxi<<" "<<secondMax<<" ";
        return (maxi-1)*(secondMax-1);
    }
};