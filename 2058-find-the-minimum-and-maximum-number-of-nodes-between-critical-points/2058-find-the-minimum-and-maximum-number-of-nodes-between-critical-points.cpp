class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int minDist = INT_MAX;
        int maxDist = -1;

        int pos = 1;
        int first = -1;
        int prev = -1;

        ListNode* prevNode = head;
        ListNode* curr = head->next;

        while (curr != nullptr && curr->next != nullptr) {
            int nextVal = curr->next->val;

            // Check if curr is a critical point
            bool isCritical =
                (curr->val > prevNode->val && curr->val > nextVal) ||
                (curr->val < prevNode->val && curr->val < nextVal);

            if (isCritical) {
                if (first == -1) {
                    // First critical point
                    first = pos;
                } else {
                    // Distance from previous critical point
                    minDist = min(minDist, pos - prev);

                    // Distance from first critical point
                    maxDist = max(maxDist, pos - first);
                }

                prev = pos;
            }

            prevNode = curr;
            curr = curr->next;
            pos++;
        }

        if (maxDist == -1) {
            return {-1, -1};
        }

        return {minDist, maxDist};
    }
};