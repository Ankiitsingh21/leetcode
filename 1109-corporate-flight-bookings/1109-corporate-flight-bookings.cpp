class Solution {
    void changee(vector <int> &arr,int l,int r,int change,int n){
        arr[l]+=change;
        if(r+1<n){
            arr[r+1]-=change;
        }
        return;
    }
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n+1,0);
        for(int i=0;i<bookings.size();i++){
            int l=bookings[i][0],r=bookings[i][1],change=bookings[i][2];
            changee(diff,l,r,change,n+1);
        }
        for(int i=1;i<=n;i++){
            diff[i]+=diff[i-1];
        }
        return vector<int>(diff.begin() + 1, diff.end());

        // for(int i=0;i<)
    }
};