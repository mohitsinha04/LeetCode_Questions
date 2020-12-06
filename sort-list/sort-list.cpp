/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* slow = head;
        ListNode* fast = head->next->next;
        while(fast && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* h = sortList(slow->next);
        slow->next = nullptr;
        return merge(sortList(head), h);
    }
    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        while(l1 && l2){
            if(l1->val < l2->val){
                curr->next = new ListNode(l1->val);
                l1 = l1->next;
            }
            else{
                curr->next = new ListNode(l2->val);
                l2 = l2->next;
            }
            curr = curr->next;
        }
        if(l1)
            curr->next = l1;
        if(l2)
            curr->next = l2;
        return dummy->next;
    }
};
