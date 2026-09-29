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
ListNode* removeElements(ListNode* head, int val) {
    
    while(head!=NULL && head->val==val){
        ListNode* temp = head;
        head= head->next;
        delete(temp);
    }

    if(head==nullptr) return head;

    ListNode* cur = head;
    while(cur->next!=nullptr){
        if(cur->next->val == val){
            ListNode* temp = cur->next;
            cur->next = cur->next->next;
            delete(temp);
        }

        if(cur->next!= nullptr && cur->next->val != val) cur = cur->next;
    }

    return head;
}
};