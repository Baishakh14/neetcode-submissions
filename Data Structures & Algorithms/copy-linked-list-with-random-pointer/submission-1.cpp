/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        unordered_map<Node*, Node*>fre;
        Node *now = new Node(0);
        now -> val = head -> val;
        fre[head] = now;
        Node *bai = now;
        Node *mah = head;
        mah = mah -> next;
        while(mah != NULL)
        {
            bai -> next = new Node(0);
            bai = bai -> next;
            bai -> val = mah -> val;
            fre[mah] = bai;
            mah = mah -> next;
        }
        Node *hi = head;
        Node *last = now;
        while(hi != NULL)
        {
            Node *ache = hi -> random;
            last -> random = fre[ache];
            hi = hi -> next;
            last = last -> next;
        }
        return now;
    }
};
