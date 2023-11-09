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
      
    public ListNode reverseList(ListNode head)
    {
        ListNode node = head;
        if(node == null || node.next == null)
        {
            return node;
        }

        
        ListNode currNode = node;
        ListNode currNodeNext = node.next;
        ListNode nextNode = reverseList(node.next);
        currNodeNext.next = currNode;
        currNode.next = null;
        return nextNode;
    }    
}