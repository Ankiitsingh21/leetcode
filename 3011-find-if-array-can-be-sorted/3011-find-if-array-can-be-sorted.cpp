class Solution {
    bool solve(vector<int>arr,vector<int> &res){
        for(int i=0;i<arr.size()-1;i++){
            for(int j=0;j<arr.size()-1-i;j++){
                if((arr[j]>arr[j+1]) ){
                    if(__builtin_popcount(arr[j])==__builtin_popcount(arr[j+1])){
                      swap(arr[j],arr[j+1]);
                    }else{
                        return false;
                    }
                }
            }
        }
        return arr==res;
    }
public:
    bool canSortArray(vector<int>& arr) {
        vector<int> ans=arr;
        sort(arr.begin(),arr.end());
        return solve(ans,arr);
    }
};