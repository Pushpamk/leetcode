/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int c = 0;
        ListNode ans = new ListNode();
        ListNode head = ans;
        while (l1 != null || l2 != null) {
            if (l1 != null) {
                c += l1.val;
                l1 = l1.next;
            }
            if (l2 != null) {
                c += l2.val;
                l2 = l2.next;
            }
            ans.next = new ListNode(c%10);
            ans = ans.next;
            c = c/10;
        }
        
        if (c != 0)
            ans.next = new ListNode(c%10);
        
        return head.next;
    }
}
