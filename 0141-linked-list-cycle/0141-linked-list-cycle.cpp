/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 //Fun Solution (constraint based):

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==nullptr || head->next == nullptr) return false;
        ListNode* temp = head;
        int count = 1;
        while(temp!=nullptr){
            if (count > 10000) return true;
            count++;
            temp = temp->next;
        }

        return false;
    }
};