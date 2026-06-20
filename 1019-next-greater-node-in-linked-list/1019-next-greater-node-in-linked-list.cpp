/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    ListNode* reversee(ListNode* head,int & cnt) {
        ListNode* temp = head;
        ListNode* prev = nullptr;
    
        while(temp){
            ListNode* store = temp->next;
            cnt++;
            temp->next = prev;
            prev = temp;
            temp = store;
        }
    
        return prev;   // new head
    }
public:
    vector<int> nextLargerNodes(ListNode* head) {
        int cnt=0;
        ListNode * temp=reversee(head,cnt);
        vector<int> ans(cnt);
        stack<int> st;
        int i=0;
        while(temp){
            while(!st.empty() && st.top()<=temp->val){
                st.pop();
            }
           if(i<cnt){ if(st.empty()){
                ans[i]=0;
                i++;
            }else{
                ans[i]=st.top();
                i++;
            }}
            st.push(temp->val);
            temp=temp->next;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};