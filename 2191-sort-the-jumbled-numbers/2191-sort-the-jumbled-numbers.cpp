class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int place = 1;
            int n = 0;
            if (num == 0) {
                n = mapping[0];
            } else {

                while (num > 0) {
                    int digit = num % 10;
                    n += mapping[digit] * place;
                    place *= 10;
                    num /= 10;
                }
            }
            pq.push({n, i});
        }
        vector<int> ans;
        while (!pq.empty()) {
            // cout<<pq.top().first<<" "<<pq.top().second<<" ";
            ans.push_back(nums[pq.top().second]);
            pq.pop();
        }
        return ans;
    }
};