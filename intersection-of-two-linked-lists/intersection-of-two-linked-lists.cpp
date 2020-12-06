/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr) return nullptr;
        ListNode* i = headA;
        ListNode* j = headB;
        
        while(i != j) {
            if(i == nullptr) i = headB;
            else i = i->next;
            
            if(j == nullptr) j = headA;
            else j = j->next;
        }
        return i;
    }
};
