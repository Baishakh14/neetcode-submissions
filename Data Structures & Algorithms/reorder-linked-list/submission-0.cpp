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
    void reorderList(ListNode* head) {
        if(head -> next == NULL || head -> next -> next == NULL) return;
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast -> next != NULL && fast -> next -> next != NULL)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        ListNode *now = new ListNode();
        ListNode *mah = slow;
        now -> val = slow -> next -> val;
        now -> next = NULL;
        mah = mah -> next;
        while(mah -> next != NULL)
        {
            ListNode *bai = new ListNode();
            bai -> val = mah -> next -> val;
            bai -> next = now;
            now = bai;
            mah = mah -> next;
        }
        slow -> next = NULL;
        ListNode *bai = new ListNode();
        ListNode *st = new ListNode();
        bai = head;
        st = head -> next;
        bai -> next = now;
        now = now -> next;
        bai = bai -> next;
        while(now != NULL)
        {
            bai -> next = st;
            st = st -> next;
            bai = bai -> next;
            bai -> next = now;
            now = now -> next;
            bai = bai -> next;
        }
        bai -> next = st;
    }
};
