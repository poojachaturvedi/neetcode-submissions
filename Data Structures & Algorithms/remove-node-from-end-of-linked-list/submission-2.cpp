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
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        int size=0;
        while(temp){
            size++;
            temp=temp->next;
        }
        int i=0;
        if(head->next==NULL){
            return nullptr;
        }
        ListNode* curr=head;
        ListNode* prev=NULL;
        while(curr){
            temp=curr->next;
            i++;
            prev=curr;
            curr=curr->next;
            if(i==size-n){
                prev->next=curr->next;
            }
        }
        if(size==n){
            return head->next;
        }
        return head;
    }
};
