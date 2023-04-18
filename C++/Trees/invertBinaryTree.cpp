struct TreeNode {
      int val;
      TreeNode *left, *right;
      TreeNode(int x){
          val = x;
          left = right = NULL;
      }
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        
        if(!root) return root;

        invertTree(root->left);
        invertTree(root->right);
        
        swap(root->left, root->right);
        
        return root;
    }
};