class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
    	// 本题要点，保证链表中节点的值互不相同
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
