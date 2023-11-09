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
    public ListNode middleNode(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;
        while(fast != null)
        {
            fast = fast.next;
            if(fast == null)   // case of odd nodes
                return slow;
            slow = slow.next;
            fast = fast.next;
        }
        return slow;    // case of even nodes
    }
}