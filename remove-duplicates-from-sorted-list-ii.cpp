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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || head -> next == NULL)
            return head;
        
        ListNode* ans = new ListNode();
        ListNode * output = ans;
        ListNode* prev = head;
        ListNode* curr = head -> next;
        ListNode* nexx = curr -> next;
        if (prev -> val != curr -> val) {
            ListNode* tmp = new ListNode();
            tmp -> val = prev -> val;
            ans -> next = tmp;
            ans = ans -> next;
        }
        while(curr -> next) {
            if (prev -> val != curr -> val && curr -> next -> val != curr -> val) {
                ListNode* tmp = new ListNode();
                tmp -> val = curr -> val;
                ans -> next = tmp;
                ans = ans -> next;
            }
            prev = curr;
            curr = curr -> next;
        }
        if (curr -> val != prev -> val) {
            ListNode* tmp = new ListNode();
            tmp -> val = curr -> val;
            ans -> next = tmp;
        }
        return output -> next;
    }
};
