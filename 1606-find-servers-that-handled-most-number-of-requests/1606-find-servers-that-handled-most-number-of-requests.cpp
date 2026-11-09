
class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        // {freeTime, serverId}
        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > busy;

        // All servers are initially available
        set<int> available;

        for (int i = 0; i < k; i++) {
            available.insert(i);
        }

        vector<int> count(k, 0);

        for (int i = 0; i < arrival.size(); i++) {

            // Release all servers whose requests have completed
            while (!busy.empty() && busy.top().first <= arrival[i]) {
                int id = busy.top().second;
                busy.pop();

                available.insert(id);
            }

            // If no server is available, drop the request
            if (available.empty()) {
                continue;
            }

            // Preferred server
            int target = i % k;

            // Find first available server >= target
            auto it = available.lower_bound(target);

            // Wrap around if no such server exists
            if (it == available.end()) {
                it = available.begin();
            }

            int server = *it;

            // Assign request to this server
            available.erase(it);

            count[server]++;

            // Calculate when server becomes free
            long long freeTime = (long long)arrival[i] + load[i];

            busy.push({freeTime, server});
        }

        // Find maximum number of requests handled
        int maxi = *max_element(count.begin(), count.end());

        vector<int> ans;

        for (int i = 0; i < k; i++) {
            if (count[i] == maxi) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
