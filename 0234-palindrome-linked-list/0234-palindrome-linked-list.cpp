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
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* head2 = fast;

        while(fast!=nullptr && fast->next!=nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }

        if(fast != nullptr){      // Odd length
        slow = slow->next;
        }

        ListNode* prev = nullptr;
        ListNode* cur = slow;
        ListNode* next = nullptr;
        while(cur!=nullptr){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        
        slow = head;
        ListNode* temp = prev;
        while(slow!=nullptr && temp!=nullptr){
            if(slow->val != temp->val) return false;
            slow = slow->next;
            temp = temp->next;
        }

        return true;
    }
};