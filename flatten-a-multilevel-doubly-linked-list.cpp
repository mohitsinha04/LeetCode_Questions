/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
​
class Solution {
public:
    Node* flatten(Node* head) {
        for(Node* h = head; h ; h = h->next) {
            if(h->child) {
                Node* next = h->next;
                h->next = h->child;
                h->next->prev = h;
                h->child = nullptr;
                Node* prev = h->next;
                while(prev->next) prev = prev->next;
                prev->next = next;
                if(next) next->prev = prev;
            }
        }
        return head;
    }
};
