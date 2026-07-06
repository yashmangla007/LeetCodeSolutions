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
    ListNode* deleteMiddle(ListNode* head) {
        //Edge case:
        if(head== nullptr || head->next== nullptr){
            return nullptr;
        }

        //starting Hare Tortoise Algo:
        //Moving till mid
        ListNode* slow= head;
        ListNode* fast= head;
        ListNode* prev = nullptr;
        while(fast!=nullptr && fast->next!= nullptr){
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }

        //Removing the middle element:
        prev->next = slow->next;
        delete slow;
        return head;
    }
};