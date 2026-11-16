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
        stack<ListNode*> st;
        ListNode* temp=head;

        if(head==NULL || head->next==NULL)
        return;

        while(temp!=NULL){
            st.push(temp);
            temp=temp->next;
        }
        int n=st.size();
        temp=head;

        for(int i=0;i<n/2;i++){
            ListNode* pop_ele=st.top();
            st.pop();
            ListNode* nextNode = temp->next;
            temp->next = pop_ele;
            pop_ele->next = nextNode;
            temp = nextNode;
        }
        temp->next=NULL;
    }
};
