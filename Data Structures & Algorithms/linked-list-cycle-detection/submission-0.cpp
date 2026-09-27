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
    bool hasCycle(ListNode* head) {
        map<ListNode *,bool>fre;
        while(head != NULL)
        {
            fre[head] = 1;
            ListNode *now = head -> next;
            if(fre.count(now)) return true;
            head = now;
        }
        return false;
    }
};
