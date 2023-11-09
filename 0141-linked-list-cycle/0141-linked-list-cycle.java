/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;
        while(slow != null && fast != null)
        {
            slow = slow.next;
            fast = fast.next;
            if(fast == null) return false;
            fast = fast.next;
            if(slow == fast)    return true;
        }
        return false;
    }
}