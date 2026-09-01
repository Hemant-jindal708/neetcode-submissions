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
        if(!head) return false;
        head->val=-2000;
        while(head->next)
        {
            if(head->next->val==-2000) return true;
            head=head->next;
            head->val=-2000;
        }
        return false;
    }
};
