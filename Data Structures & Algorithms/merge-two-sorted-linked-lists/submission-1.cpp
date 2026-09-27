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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *ans = new ListNode();
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;
        int v1 = list1 -> val;
        int v2 = list2 -> val;
        if(v1 < v2)
        {
            ans -> val = v1;
            list1 = list1 -> next;
        }
        else 
        {
            ans -> val = v2;
            list2 = list2 -> next;
        }
        ListNode *now = ans;
        while(list1 != NULL && list2 != NULL)
        {
            int v1 = list1 -> val;
            int v2 = list2 -> val;
            ListNode *cur = new ListNode();
            if(v1 < v2)
            {
                cur -> val = v1;
                list1 = list1 -> next;
            }
            else 
            {
                cur -> val = v2;
                list2 = list2 -> next;
            }
            now -> next = cur;
            now = cur;
        }
            while(list1 != NULL)
            {
            ListNode *cur = new ListNode();
            cur -> val = list1 -> val;
            now -> next = cur;
            now = cur;
            list1 = list1 -> next;
            }

        while(list2 != NULL)
            {
            ListNode *cur = new ListNode();
            cur -> val = list2 -> val;
            now -> next = cur;
            now = cur;
            list2 = list2 -> next;
            }
        return ans;
    }
};
