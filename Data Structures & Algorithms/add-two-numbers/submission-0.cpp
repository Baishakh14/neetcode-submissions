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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head;
        ListNode *ans = new ListNode();
        int carry = 0;
        int num1 = l1 -> val;
        int num2 = l2 -> val;
        carry = carry + num1 + num2;
        int ld = carry % 10;
        ans -> val = ld;
        carry /= 10;
        l1 = l1 -> next;
        l2 = l2 -> next;
        head = ans;
        while(l1 != NULL && l2 != NULL)
        {
            num1 = l1 -> val;
            num2 = l2 -> val;
            carry = carry + num1 + num2;
            ans -> next = new ListNode();
            ans -> next -> val = carry % 10;
            carry /= 10;
            ans = ans -> next;
            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        while(l1 != NULL)
        {
            int num = l1 -> val;
            carry = carry + num;
            ans -> next = new ListNode();
            ans -> next -> val = carry % 10;
            carry /= 10;
            ans = ans -> next;
            l1 = l1 -> next;
        }
        while(l2 != NULL)
        {
            int num = l2 -> val;
            carry = carry + num;
            ans -> next = new ListNode();
            ans -> next -> val = carry % 10;
            carry /= 10;
            ans = ans -> next;
            l2 = l2 -> next;
        }
        if(carry > 0)
        {
            ans -> next = new ListNode();
            ans -> next -> val = carry;
        }
        return head;
    }
};
