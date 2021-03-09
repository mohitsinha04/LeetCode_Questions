/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if (!head) {
        // create a single node circular list
        Node* inserted_node = new Node(insertVal);
        inserted_node->next = inserted_node;
        return inserted_node;
      }
      
      Node* cur = head;
      
      // loop list to find insertion position: cur->next
      for (; cur->next != head; cur = cur->next) {
        int curVal = cur->val;
        int nextVal = cur->next->val;
        
        // curVal is max (nextVal is min), and insertVal is outside (min, max)
        if (curVal > nextVal && (insertVal >= curVal || insertVal <= nextVal)) break;
        
        // insertVal is inside [curVal, nextVal]
        if (curVal <= insertVal && insertVal <= nextVal) break; 
      }
      
      // insert a new node
      Node* inserted_node = new Node(insertVal, cur->next);
      cur->next = inserted_node;
      
      return head;
    }
};