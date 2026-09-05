/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* fast = head;
        if (head == NULL || head->next == NULL || head->next->next == NULL) {
            return NULL;
        }
        unordered_map<ListNode*, int> mpp;
        while (fast != NULL && fast->next != NULL) {
            if(mpp.find(fast)==mpp.end())
            {
                mpp[fast]++;
                fast=fast->next;
            }
            else
            {
                return fast;
            }
        }
        return NULL;
    }
};