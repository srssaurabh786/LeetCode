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
    ListNode* deleteMiddle(ListNode* head) {

        //approach 1

        // if(head == NULL || head->next == NULL)
        // return NULL;
        // ListNode* curr=head;
        // int n=0;
        // while(curr)
        // {
        //  n++;
        //  curr=curr->next;
        // }
        // n=(n/2)+1;
        //  curr=head;
        // while(n--)
        // {
        //   curr=curr->next;
        // }
        // delete curr;
        // return head;

        //approach 2
        
         if(head == NULL || head->next == NULL)
         return NULL;

         ListNode* fast=head;
         ListNode* slow=head;
         ListNode* prev=NULL;

         while(fast && fast->next)
         {  prev=slow;
            fast=fast->next->next;
            slow=slow->next;
         }

         prev->next=slow->next;
         delete slow;
         return head;

    }
};