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
        ListNode* first=list1;
        ListNode* second=list2;
        if(list1==NULL && list2==NULL)
        {
            return NULL;
        }
        else if(list1==NULL)
        {
            return list2;
        }
        else if(list2==NULL)
        {
            return list1;
        }
        ListNode* newHead = new ListNode(-1);
        ListNode* temp=newHead;
        while(first!=NULL && second!=NULL)
        {
            if(first->val<=second->val)
            {
                temp->next=first;
                first=first->next;
            }
            else
            {
                temp->next=second;
                second=second->next;
            }
            temp=temp->next;
        }
        while(first!=NULL)
        {
            temp->next=first;
            first=first->next;
            temp=temp->next;
        }
        while(second!=NULL)
        {
            temp->next=second;
            second=second->next;
            temp=temp->next;
        }
        
        return newHead->next;
    }
};