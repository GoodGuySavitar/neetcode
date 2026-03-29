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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* first = l1;
        ListNode* second = l2;

        ListNode* newHead = new ListNode(-1);
        ListNode* temp = newHead;
        
        int carry = 0; 

        while(first != NULL || second != NULL || carry != 0){
            int sum = (first ? first->val : 0) + (second ? second->val : 0) + carry;

            carry = sum / 10;
            sum = sum % 10;
            ListNode* newNode = new ListNode(sum);
            temp->next = newNode;
            temp = temp->next;

            first = (first != NULL ? first->next : NULL);
            second = (second != NULL ? second->next : NULL);
        }

        return newHead->next;

    }
};
