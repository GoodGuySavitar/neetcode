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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return head;
        ListNode* temp = head;
        int total = 0;
        int overallCount = 0;
        int count = 0;

        while(temp != nullptr){
            temp = temp->next; 
            total++;
        }

        if(k > total) return head;

        temp = head;
        ListNode* front = temp;
        ListNode* prev = nullptr;
        vector<pair<ListNode*, ListNode*>> heads;
        ListNode* currHead = head;

        while(total - overallCount >= k){
            if(count == 0){
                currHead = temp;
            }
            while(count < k){
                front = temp->next;
                temp->next = prev;
                prev = temp;
                temp = front;

                count++;
                overallCount++;
            }
            heads.push_back({currHead, prev});
            prev = nullptr;
            count = 0;
        }

        for(int i = 1; i < heads.size(); ++i){
            heads[i-1].first->next = heads[i].second;
        }

        heads[heads.size()-1].first->next = temp;

        if(!heads.empty()) return heads[0].second;

        return head;
    }
};
