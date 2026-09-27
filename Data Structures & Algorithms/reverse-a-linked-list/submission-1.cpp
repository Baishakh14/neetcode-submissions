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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return head;
        ListNode *age = new ListNode();
        age -> val = head -> val;
        while(head -> next != NULL)
        {
            ListNode *pore = new ListNode();
            pore -> val = head -> next -> val;
            pore -> next = age;
            age = pore;
            head = head -> next;
        }
        return age;
    }
};
