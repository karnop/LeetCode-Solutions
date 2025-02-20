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

    ListNode* add(ListNode* l1, ListNode* l2, int carry) {
        if (!l1 && !l2) {
            return carry ? new ListNode(carry) : nullptr;
        }

        int sum = carry;
        if (l1) sum += l1->val;
        if (l2) sum += l2->val;
        
        carry = sum / 10;
        sum = sum % 10;

        ListNode* result = new ListNode(sum);
        result->next = add(l1 ? l1->next : nullptr, l2 ? l2->next : nullptr, carry);
        return result;
    }


    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = add(l1, l2, 0);
        return res;
    }
};