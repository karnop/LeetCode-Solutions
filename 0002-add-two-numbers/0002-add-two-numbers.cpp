/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* add(int carry, ListNode* l1, ListNode* l2){
        if(!l1 && !l2) {
            if(carry == 0) return nullptr;
            return new ListNode(carry);
        }
        int sum = carry + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
        carry = sum/10;
        sum = sum%10;
        ListNode* ans = new ListNode(0);
        ans->val = sum;
        ans->next = add(carry, (l1 ? l1->next : nullptr), (l2 ? l2->next : nullptr));
        return ans;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = add(0, l1, l2);
        return head;
    }
};