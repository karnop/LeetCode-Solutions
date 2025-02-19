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
    ListNode* middleNode(ListNode* head) {
        ListNode* med = head;
        ListNode* tail = head;
        while(tail!=nullptr && tail->next != nullptr) {
            tail = tail->next->next;
            med = med->next;
        }
        return med;
    }
};