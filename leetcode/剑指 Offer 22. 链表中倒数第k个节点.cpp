class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        // 正数n-k
        ListNode* node = head;
        int num = 0;

        while(node) {
            num ++;
            node = node->next;
        }

        node = head;

        for(int i = 0; i < num - k; i++) {
            node = node->next;
        }

        return node;  
    }
};

//滑动窗口
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* slow = head;
        ListNode* fast = head;

        for(int i=1; i<k; i++) {
            fast = fast->next;
        }

        while(fast->next) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};