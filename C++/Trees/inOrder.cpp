void inOrder(Node *root) {
        if(root == nullptr) return;
        preOrder(root->left);
         cout<<root->data<<" ";
        preOrder(root->right);
    }