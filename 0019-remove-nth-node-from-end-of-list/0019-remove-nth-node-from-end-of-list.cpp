class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        //checking basic  conditions
        if(head==NULL)return head;
        if(n==0)return head;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        while(n!=0){
            fast = fast->next;
            n--;
        }

        while(fast!=NULL){
            prev = slow;
            fast=fast->next;
            slow=slow->next;
        }

        if(prev==NULL){
            ListNode* newHead = slow->next;
            delete slow;
            return newHead;
        }

        prev->next = slow->next;
        delete slow;
        return head;
    }
};