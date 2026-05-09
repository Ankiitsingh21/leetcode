class Solution {
    vector<vector<int>> dp;
    vector<vector<int>> choice;
    int solve(int index, vector<int>& people, int mask, int req) {
        if (mask == req)
            return 0;
        if (index == people.size())
            return 1e9;

        if(dp[index][mask]!=-1) return dp[index][mask];
        int take = 1 + solve(index + 1, people, (mask | people[index]), req);
        int nottake = solve(index + 1, people, mask, req);

        choice[index][mask] = (take < nottake) ? 1 : 0;
        return dp[index][mask] = min(take, nottake);
    }
    void construct(int index, vector<int>& people, int mask, int req,
                   vector<int>& ans) {
        if (mask == req || index == people.size())
            return;
        if (choice[index][mask] == 1) {
            ans.push_back(index);
            construct(index + 1, people, (mask | people[index]), req, ans);
            // ans.pop_back();
        } else {
            construct(index + 1, people, mask, req, ans);
        }
        return;
    }

public:
    vector<int> smallestSufficientTeam(vector<string>& arr,
                                       vector<vector<string>>& peoples) {
        unordered_map<string, int> mpp;
        for (int i = 0; i < arr.size(); i++) {
            mpp[arr[i]] = i;
        }
        vector<int> people;
        for (int i = 0; i < peoples.size(); i++) {
            int h = 0;
            for (string& ch : peoples[i]) {
                h |= 1 << (mpp[ch]);
            }
            people.push_back(h);
        }
        int reqmask = (1 << arr.size()) - 1;
        dp.resize(peoples.size() + 1, vector<int>(1 << arr.size(), -1));
        choice.resize(peoples.size() + 1, vector<int>(1 << arr.size(), -1));
        solve(0, people, 0, reqmask);

        vector<int> ans;
        construct(0, people, 0, reqmask, ans);
        // cout<< solve(0,people,0,reqmask)<<" ";
        return ans;
    }
};