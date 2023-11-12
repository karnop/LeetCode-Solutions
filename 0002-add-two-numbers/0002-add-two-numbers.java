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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) 
    {
        int carry = 0;
        ListNode ans = new ListNode();
        ListNode top = ans;

        while(l1!=null || l2!=null)
        {
            int val1 = (l1==null ? 0 : l1.val);
            int val2 = (l2==null ? 0 : l2.val);

            int sum = val1 + val2 + carry;
            carry = (sum > 9 ? 1 : 0);
            if(sum > 9) sum = sum-10; 

            ListNode n = new ListNode(sum);
            top.next = n;
            top = n;

            if(l1 != null) l1 = l1.next;
            if(l2 != null) l2 = l2.next;
        }   

        if(carry == 1)
        {
            ListNode n = new ListNode(1);
            top.next = n;
            top = n;
        }   

        return ans.next;
    }
}