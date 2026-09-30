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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *ans = new ListNode();
        ans -> val = 0;
priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>pq;
        ListNode *now = ans;
        for(auto it : lists)
        {
            if(it == NULL) continue;
            pq.push({it -> val,it});
        }
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            now -> next = new ListNode();
            now -> next -> val = it.first;
            now = now -> next;
            if(it.second -> next != NULL)
            {
                pq.push({it.second -> next -> val,it.second -> next});
            }
        }
        return ans -> next;
    }
};
