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
    int maxDepth(TreeNode* root) {
        
        if(!root) return 0;
        
        int leftMost = maxDepth(root->left);
        int rightMost = maxDepth(root->right);
        
        return 1 + max(leftMost, rightMost);
    }
};