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

    public int gcd(int a, int b)
    {
        if(a == 0)  return b;
        if(a >= b) return gcd(a%b, b);
        else        return gcd(b%a, a);

    }
    public ListNode insertGreatestCommonDivisors(ListNode head) 
    {

        ListNode temp = head;
        while(temp!=null && temp.next != null)
        {
            ListNode curr = temp;
            ListNode nextt = temp.next;
            int data = gcd(curr.val, nextt.val);
            ListNode n = new ListNode(data);
            curr.next = n;
            n.next = nextt;
            temp = temp.next.next;
        }  
        return head;  
    }
}