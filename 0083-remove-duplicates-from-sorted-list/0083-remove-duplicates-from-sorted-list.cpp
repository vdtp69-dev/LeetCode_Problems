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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode *temp = head;
        ListNode *fast = head->next;
        while(temp!=NULL)
        {
            while(fast!=NULL && fast->val == temp->val)
            {
                fast=fast->next;
            }
            if(fast == NULL) break;
            temp->next=fast;
            temp=temp->next;
        }
        temp->next=NULL;
        return head;

    }
};