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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;

        while(lists.size() > 1){
            vector<ListNode*> mergeLists;
            for(int i = 0; i < lists.size(); i+=2){
                ListNode* list1 = lists[i];
                ListNode* list2 = (i + 1) < lists.size() ?  lists[i+1] : nullptr;
                mergeLists.push_back(mergeList(list1, list2));
            }
            lists = mergeLists;
        }
        return lists[0];
    }

private: 
    ListNode* mergeList(ListNode* head1, ListNode* head2){
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        ListNode* l1 = head1;
        ListNode* l2 = head2;
        
        while(l1 != nullptr && l2 != nullptr){
            if(l1->val < l2->val){
                temp->next = l1;
                l1 = l1->next;
            }
            else {
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }

        if(l1 != nullptr){
            temp->next = l1;
        }

        if(l2 != nullptr){
            temp->next = l2;
        }

        return dummy->next;
    }

};
