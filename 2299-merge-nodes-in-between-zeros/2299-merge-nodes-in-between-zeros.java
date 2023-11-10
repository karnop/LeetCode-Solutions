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
    public ListNode mergeNodes(ListNode head) 
    {
        ListNode curr = head;
        ListNode nxt = head;
        ListNode prev = null;

        int sum = 0;
        while(nxt!=null && nxt.next != null)
        {
            nxt = nxt.next;
            if(nxt.val == 0)
            {
                ListNode n = new ListNode(sum);
                sum = 0;
                curr.next = n; n.next = nxt;
                // removing 0
                if(curr == head) head = n;
                if(nxt.next == null)  n.next = null;
                if(prev != null) prev.next = n;                
                curr = nxt;
                prev = n;
            }

            sum = sum + nxt.val;
        }
        return head;
    }
}