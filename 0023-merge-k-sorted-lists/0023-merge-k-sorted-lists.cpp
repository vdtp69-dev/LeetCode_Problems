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
        vector<int>ans;
        for(auto it:lists)
        {
            while(it!=NULL)
            {
                ans.push_back(it->val);
                it=it->next;
            }
        }
        sort(ans.begin(),ans.end());
        ListNode* dummyNode=new ListNode(-1);
        ListNode* temp=dummyNode;
        for(int i=0;i<ans.size();i++)
        {
            ListNode* newNode=new ListNode(ans[i]);
            temp->next=newNode;
            temp=temp->next;
        }
        temp->next=NULL;
        return dummyNode->next;
    }
};