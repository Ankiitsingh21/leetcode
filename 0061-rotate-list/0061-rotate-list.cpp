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
    ListNode * rotate(ListNode * head){
        if(!head || !head->next){
            return head;
        }
        ListNode * prev=NULL;
        ListNode * temp=head;
        while(temp->next){
            prev=temp;
            temp=temp->next;
        }
        prev->next=NULL;
        temp->next=head;
        return temp;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head){
            return head;
        }
        ListNode * temp=head;
        int n=0;
        while(temp){
            n++;
            temp=temp->next;
        }
        k=k%n;
        if(k==0){
            return head;
        }
        int cnt=0;
        while(cnt<k){
            // cout<<" hi"<<" "<<endl;
            head=rotate(head);
            cnt++;
        }
        return head;
    }
};