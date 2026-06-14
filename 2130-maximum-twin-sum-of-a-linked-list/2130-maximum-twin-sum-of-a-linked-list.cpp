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
    ListNode *reverse(ListNode * temp){
        ListNode * prev=NULL;
        while(temp){
            ListNode * store=temp->next;
            temp->next=prev;
            prev=temp;
            temp=store;
        }
        return prev;
    }
public:
    int pairSum(ListNode* head) {
        ListNode * slow=head;
        ListNode * fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        slow=reverse(slow);
        int sum=0;
        ListNode * temp=head;
        while(slow){
            sum=max(sum,temp->val+slow->val);
            slow=slow->next;
            temp=temp->next;
        }
        // cout<<slow->val<<" ";
        return sum;
    }
};