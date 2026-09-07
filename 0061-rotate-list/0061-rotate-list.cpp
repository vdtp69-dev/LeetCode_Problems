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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* kNode=head;
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        int last=lengthNode(head);
        k%=last;
        if(k==0)return head;
        kNode=kthNode(temp,last);
        reverseList(temp);
        head=kNode;
        temp=head;
        kNode=kthNode(temp,k);
        ListNode* nextNode=kNode->next;
        kNode->next=NULL;
        reverseList(temp);
        if(temp==head)head=kNode;
        ListNode*prevNode=temp;
        temp=nextNode;
        kNode=kthNode(temp,last-k);
        reverseList(temp);
        prevNode->next=kNode;
        return head;

    }
     ListNode* kthNode(ListNode* temp,int k) {
        k-=1;
        while(temp!=NULL && k>0)
        {
            k--;
            temp=temp->next;
        }
        return temp;
    }
    int lengthNode(ListNode* head)
    {
        ListNode* temp=head;
        int count=0;
        while(temp!=NULL)
        {
            temp=temp->next;
            count++;
        }
        return count;
    }
    ListNode* reverseList(ListNode* head)
    {
         if(head==NULL || head->next==NULL)
        {
            return head;
        }
        ListNode* temp=head;
        ListNode* prev=NULL;
        ListNode* front=temp->next;
        while(front!=NULL)
        {
            temp->next=prev;
            prev=temp;
            temp=front;
            front=front->next;
        }
        temp->next=prev;
        ListNode* mainHead=temp;
        return temp;
    }
};