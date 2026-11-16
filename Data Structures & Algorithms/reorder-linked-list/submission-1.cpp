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
    void reorderList(ListNode* head) {
        //find the middle element
        ListNode* fast=head;
        ListNode* slow=head;

        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        //reverse the last half
        ListNode * curr=slow->next;
        slow->next=NULL;
        ListNode * prev=NULL;
        while(curr){
            ListNode* temp=curr->next;
            curr->next = prev;
            prev=curr;
            curr=temp;
        }
        //merge alternately
        ListNode* first=head;
        ListNode* second=prev;

        while(second){
            ListNode* node1=first->next;
            ListNode* node2=second->next;

            first->next=second;
            second->next=node1;

            first=node1;
            second=node2;
        }
    }
};
