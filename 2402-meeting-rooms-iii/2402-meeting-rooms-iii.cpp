class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& nums) {
        sort(nums.begin(), nums.end(), [](const vector<int>& a, const vector<int>& b){
            return a[0] < b[0];
        });
        priority_queue<int,vector<int>,greater<int>> fr;
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        // map<int,int> mpp;
        vector<int> mpp(n,0);
        for(int i=0;i<n;i++){
            // mpp[i]=0;
            fr.push(i);
        }
        for(int i=0;i<nums.size();i++){
            while(!pq.empty() && pq.top().first<=nums[i][0]){
                auto [end,room] = pq.top();
                pq.pop();
                fr.push(room);
            }
            if(!fr.empty()){
                int room=fr.top();
                fr.pop();
                mpp[room]++;
                pq.push({nums[i][1], room});
            }else{
                auto [end,room] = pq.top();
                pq.pop();
                mpp[room]++;
                int duration = nums[i][1] - nums[i][0];
                pq.push({end + duration, room});
            }
        }
        int ans = 0;

        for(int i = 1; i < n; i++){
            if(mpp[i] > mpp[ans]){
                ans = i;
            }
        }
        
        return ans;
        
        // return ans;
        // return pq.top().second;
    }
};