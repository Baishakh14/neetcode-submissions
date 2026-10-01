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
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<int>vec;
        ListNode *now = head;
        vector<int>ab;
        while(now != NULL)
        {
            ab.push_back(now -> val);
            now = now -> next;
            if(ab.size() == k)
            {
                for(int i = ab.size() - 1;i>=0;i--)
                vec.push_back(ab[i]);
                ab.clear();
            }
        }
        for(auto it : ab) vec.push_back(it);
        ListNode *ans = new ListNode(0);
        ListNode *final = ans;
        for(auto it : vec)
        {
            ans -> next = new ListNode();
            ans -> next -> val = it;
            ans = ans -> next;
        }
        return final -> next;
    }
};
