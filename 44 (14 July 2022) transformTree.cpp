void helper(struct Node *root, int &sum){
        if(root == NULL){
            return;
        }
        
        helper(root->right,sum);
        int temp = root->data;
        root->data = sum;
        sum += temp;
        
        helper(root->left, sum);
    }
    
    void transformTree(struct Node *root)
    {
        //code here
        int sum = 0;
        helper(root,sum);
    }
