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

    public ListNode findmid(ListNode head)
    {
        ListNode slow = head;
        ListNode fast = head;
        while(fast!=null && fast.next!=null)
        {
            fast = fast.next.next;
            slow = slow.next;
        }
        return slow;
    }

    public ListNode reverse(ListNode head)
    {
        if(head.next == null)   return head;

        ListNode curr = head;
        ListNode currNext = reverse(head.next);
        ListNode nextt = curr.next;
        curr.next = null;
        nextt.next = curr;
        return currNext;
    }

    public void display(ListNode head)
    {
        if(head==null)  return;
        display(head.next);
    }

    public int pairSum(ListNode head) {

        ListNode list1 = head;
        ListNode mid = findmid(head);
        ListNode list2 = reverse(mid);
    

        int maxSum = Integer.MIN_VALUE;
        while(list1!=null && list2!=null)
        {
            int sum = list1.val + list2.val;
            maxSum = Math.max(sum, maxSum);
            list1 = list1.next;
            list2 = list2.next;
        }
        return maxSum;
    }
}