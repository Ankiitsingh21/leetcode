class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<nums.size();i++){
            int num=nums[i];
            vector<int> arr;
            string s=to_string(num);
            for(char c:s){
                arr.push_back(mapping[c-'0']);
            }
            int n=0;
            for(int i=0;i<arr.size();i++){
                n=n*10+arr[i];
            }
            pq.push({n,i});            
        }
        vector<int> ans;
        while(!pq.empty()){
            // cout<<pq.top().first<<" "<<pq.top().second<<" ";
            ans.push_back(nums[pq.top().second]);
            pq.pop();
        }
        return ans;
    }
};