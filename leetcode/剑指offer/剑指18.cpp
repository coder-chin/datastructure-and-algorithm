class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if(!head) return head;

        if(head->val == val) {
            return head->next;
        }

        ListNode* pre = head;
        ListNode* curr = head->next;

        while(curr && curr->val!=val) {
            pre = pre->next;
            curr = curr->next;
        }

        if(curr) {
            pre->next = curr->next;
        } 
        
        return head;
    }
};