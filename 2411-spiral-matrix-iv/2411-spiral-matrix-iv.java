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
    
    public int[][] spiralMatrix(int m, int n, ListNode head) 
    {
        int[][] arr = new int[m][n];

        // traversing array
        int top = 0, left = 0;
        int right = n-1, bottom = m-1;
        int data;
        while(top<=bottom && left<=right)
        {
            for(int i=left; i<=right; i++)
            {   
                if(head == null)    data = -1;
                else 
                {
                    data = head.val;
                    head = head.next;
                }
                arr[top][i] = data;
            }
            top++;  if(top>bottom || left>right)  break;

            for(int i=top; i<=bottom; i++)
            {
                if(head == null)    data = -1;
                else 
                {
                    data = head.val;
                    head = head.next;
                }
                arr[i][right] = data;
            }
            right--;  if(top>bottom || left>right)  break;

            for(int i=right; i>=left; i--)
            {
                if(head == null)    data = -1;
                else 
                {
                    data = head.val;
                    head = head.next;
                }
                arr[bottom][i] = data;
            }
            bottom--;  if(top>bottom || left>right)  break;

            for(int i=bottom; i>=top; i--)
            {
                if(head == null)    data = -1;
                else 
                {
                    data = head.val;
                    head = head.next;
                }
                arr[i][left] = data;
            }
            left++;
        }

        // ans 
        return arr;
           
    }
}