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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt = 0;
        ListNode *now = head;
        while(now != NULL)
        {
            cnt++;
            now = now -> next;
        }
        n = cnt - n + 1;
        if(n == 1)
        {
            return head = head -> next;
        }
        cnt = 1;
        ListNode *f = head;
        ListNode *s = head -> next;
        while(s != NULL)
        {
            cnt++;
            if(cnt == n)
            {
                f -> next = s -> next;
                break;
            }
            s = s -> next;
            f = f -> next;
        }
        return head;
    }
};
