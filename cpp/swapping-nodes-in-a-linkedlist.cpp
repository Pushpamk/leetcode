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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* endSwap = head;
        for (int i = 1; i <= k - 1; i++) {
            slow = slow -> next;
            fast = fast -> next;
        }
        fast = fast -> next;
        if (!fast) {
            int tmp = slow -> val;
            slow -> val = endSwap -> val;
            endSwap -> val = tmp;
            return head;
        }
        
        while(fast -> next) {
            fast = fast -> next;
            endSwap = endSwap -> next;
        }
        int tmp = slow -> val;
        slow -> val = endSwap -> next -> val;
        endSwap -> next -> val = tmp;
        return head;
    }
};
