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
    public ListNode[] splitListToParts(ListNode head, int k) 
    {
        ListNode[] list = new ListNode[k];
        
        // size of list
        int size = 0;
        ListNode temp = head;
        while(temp!=null){size++; temp=temp.next;}

        // elements per list
        int elems = size/k;
        int rem = size%k;
        temp = head;

        for(int i=0; i<k; i++)
        {
                ListNode head0 = new ListNode(0);
                ListNode tail = head0;
                for(int j=0; j<elems + (i<rem ? 1 : 0); j++)
                {
                    if(temp!=null)
                    {
                        ListNode n = new ListNode(temp.val);
                        tail.next = n;
                        tail = tail.next;
                        temp = temp.next;
                    }
                }
                list[i] = head0.next;
        }
        return list;    
    }
}