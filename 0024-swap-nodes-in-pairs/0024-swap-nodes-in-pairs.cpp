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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL ||head->next==NULL)
        {
            return head;
        }
        ListNode* temp = head;
        ListNode* kNode = head->next;
        ListNode* prevNode = temp;
        int k = 2;
        while (temp != NULL) {
            kNode = kthNode(temp, k);
            if(kNode==NULL)
            {
                if(prevNode)prevNode->next=temp;
                break;
            }
            ListNode* nextNode = kNode->next;
            kNode->next = NULL;
            reverseList(temp);
            if (temp == head)
                head = kNode;
            else {
                prevNode->next = kNode;
            }
            prevNode = temp;
            temp = nextNode;
        }
        return head;
    }
    ListNode* kthNode(ListNode* temp, int k) {
        k -= 1;
        while (temp != NULL && k > 0) {
            k--;
            temp = temp->next;
        }
        return temp;
    }
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* temp = head;
        ListNode* prev = NULL;
        ListNode* front = temp->next;
        while (front != NULL) {
            temp->next = prev;
            prev = temp;
            temp = front;
            front = front->next;
        }
        temp->next = prev;
        ListNode* mainHead = temp;
        return temp;
    }
};