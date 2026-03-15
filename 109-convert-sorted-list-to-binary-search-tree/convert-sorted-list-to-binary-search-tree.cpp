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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    TreeNode* sortedListToBST(ListNode* head) {
        //poor method for middle

        // ListNode* temp=head;
        // int n=0;
        // while(temp)
        // {
        //   n++;
        //   temp=temp->next;
        // }
        //  temp=head;
        // while(n--)
        // {
        //   temp=temp->next;
        // }
         
         //edge case
         if(head==NULL)
         return NULL;
         if(head->next==NULL)
         return new TreeNode(head->val);
        //smar method for middle
        ListNode* fast=head;
        ListNode* slow=head;
        ListNode* slowprev=NULL;
        
        while(fast!=NULL && fast->next!=NULL)
        {   slowprev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }

        //slow pakka mid ko point kr rha hoga
        TreeNode* root=new TreeNode(slow->val);
        
        slowprev->next=NULL;

        root->left=sortedListToBST(head);

        root->right=sortedListToBST(slow->next);

        return root;
    }
};