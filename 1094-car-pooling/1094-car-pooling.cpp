class Solution {
    void changee(vector<int> &arr,int l,int r,int change,int n){
        arr[l]+=change;
        if(r+1<n){
            arr[r+1]-=change;
        }
        return ;
    }
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n=INT_MIN;
        for(int i=0;i<trips.size();i++){
            n=max(n,trips[i][2]);
        }
        vector<int> diff(n,0);
        for(int i=0;i<trips.size();i++){
            int l=trips[i][1],r=trips[i][2]-1,change=trips[i][0];
            changee(diff,l,r,change,n);
        }
        if(diff[0]>capacity){
            return false;
        }
        for(int i=1;i<n;i++){
            diff[i]+=diff[i-1];
            if(diff[i]>capacity){
                return false;
            }
        }
        return true;
    }
};