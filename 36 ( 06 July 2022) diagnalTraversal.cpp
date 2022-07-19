void diagnalTraversal(Node*root, queue<Node*>&q, vector<int> &v){
    if (root==NULL) return;
    q.push(root->left);
    v.push_back(root->data);
    diagnalTraversal(root->right,q,v);
}

vector<int> diagonal(Node *root) {
    queue<Node*>q;
    vector<int>v;
    q.push(root);
    while(!q.empty()){
        Node * x = q.front();
        q.pop();
        diagnalTraversal(x,q,v);
    }
    return v;
}
