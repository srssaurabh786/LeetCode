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
 int n1,n2;
class Solution {
public:
    void Find(TreeNode* root,int &sum)
  {
      if(!root)
      return;
      
      if(root->val > n1 && root->val > n2)
      Find(root->left,sum);
      
      else if(root->val < n1 && root->val < n2)
      Find(root->right,sum);
      
      else
      {
          Find(root->left,sum);
          sum +=root->val;
          Find(root->right,sum);
      }
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        n1=low,n2=high;
        int sum=0;
        Find(root,sum);
        return sum;
    }
};

