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
    public ListNode deleteDuplicates(ListNode head) {
        ListNode curr = head;
        ListNode nextt;
        while(curr != null)
        {
            nextt = curr.next;
            if(nextt!=null && curr.val == nextt.val)
            {
                while(nextt.next != null && nextt.next.val == nextt.val)  nextt=nextt.next;
                nextt=nextt.next;
                curr.next = nextt;
            }

            curr = curr.next;
        }
        return head;
    }
}