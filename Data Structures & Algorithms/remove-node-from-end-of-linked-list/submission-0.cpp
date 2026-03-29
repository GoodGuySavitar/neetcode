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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        if(head == NULL) return head;
        
        int len = 0;
        while(temp != NULL){
            temp = temp->next;
            len++;
        }

        int k = len-n;
        if(k == 0) return head->next;

        temp = head;
        for(int i = 0; i < len-1; ++i){
            if(i+1 == k){
                temp->next = temp->next->next;
                break;
            }
            temp = temp->next;
        }

        return head;
    }
};