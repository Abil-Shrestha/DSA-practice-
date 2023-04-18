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
    
    int getHeight(TreeNode* root){
        
        if(!root) return 0;
        
        int lt = getHeight(root->left);
        int rt = getHeight(root->right);
        if(lt == -1 || rt == -1) return -1;
        
        if(abs(lt - rt) > 1) return -1;
        
        return 1 + max(lt, rt);
    }
    
    bool isBalanced(TreeNode* root) {
        
        return (getHeight(root) != -1);
    }
};