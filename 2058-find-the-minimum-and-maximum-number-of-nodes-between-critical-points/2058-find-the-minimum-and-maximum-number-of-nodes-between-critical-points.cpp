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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head==NULL || head->next==NULL || head->next->next==NULL)
        {
            return {-1,-1};
        }
        vector<int>indices;
        ListNode* prev=head;
        ListNode* temp=head->next;
        int count=2;
        while(temp!=NULL)
        {
            if(temp->next!=NULL && temp->val > prev->val && temp->val >temp->next->val)
            {
                indices.push_back(count);
            }
            else if(temp->next!=NULL && temp->val < prev->val && temp->val < temp->next->val)
            {
                indices.push_back(count);
            }
            prev=temp;
            temp=temp->next;
            count++;
        }
        int n=indices.size();
        if(n==0 || n==1)
        {
            return {-1,-1};
        }
        else
        {
            int mini=INT_MAX;
            for(int i=1;i<n;i++)
            {
                mini=min(mini,indices[i]-indices[i-1]);
            }
            return {mini,(indices[n-1]-indices[0])};
        }
    }
};