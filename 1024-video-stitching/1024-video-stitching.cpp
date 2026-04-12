class Solution {
public:
    int videoStitching(vector<vector<int>>& arr, int time) {
        sort(arr.begin(),arr.end(),[](auto &a,auto &b){
            if(a[0]==b[0]){
                return a[1]>b[1];
            }
            return a[0]<b[0];
        });
        // for(int i=0;i<arr.size();i++){
        //     cout<<arr[i][0]<<" "<<arr[i][1]<<" "<<endl;;
        // }
        int end=0;
        int cnt=0;
        int maxi=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i][0]>end) return -1;
            if(arr[i][0]>maxi){
                cnt++;
                // cout<<arr[i][0]<<" "<<arr[i][1]<<" ";
                maxi=end;
            }

            end=max(end,arr[i][1]);
            if(end>=time) break; 
        }
        if(end < time) return -1;
        return cnt+1;
    }
};