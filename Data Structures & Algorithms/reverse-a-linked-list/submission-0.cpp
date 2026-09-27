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
        if(head == NULL)
        {
            return head;
        }
        vector<int>ab;
        ListNode *now = head;
        while(now != NULL)
        {
            ab.push_back(now -> val);
            now = now -> next;
        }
        reverse(ab.begin(),ab.end());
        ListNode *ans;
        ans = new ListNode();
        ans -> val = ab[0];
        ans -> next = NULL;
        head = ans;
        for(int i = 1;i<ab.size();i++)
        {
            ListNode *hi;
            hi = new ListNode();
            hi -> val = ab[i];
            hi -> next = NULL;
            head -> next = hi;
            head = hi;
        }
        return ans;
    }
};
