int maxPathSum(Node* root)
    {
        if(!root) return 0;
        return (root->data + max(maxPathSum(root->left), maxPathSum(root->right)));
    }
