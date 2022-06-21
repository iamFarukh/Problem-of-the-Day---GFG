int sizeofbst(Node*root){
     if(root==NULL)return 0;
     int lh=sizeofbst(root->left);
     int rh=sizeofbst(root->right);
     return 1+lh+rh;
 }
 bool isBst(Node*root,int min,int max){
     if(root==NULL)return true;
     if(root->data<=min or root->data>=max){
         return false;
     }
     bool lh=isBst(root->left,min,root->data);
     bool rh=isBst(root->right,root->data,max);
     return lh and rh;
 }
 int largestBst(Node *root)
 {
  //Your code here
  if(root==NULL)return 0;
  if(isBst(root,INT_MIN,INT_MAX)){
      return sizeofbst(root);
  }
  int lh=largestBst(root->left);
  int rh=largestBst(root->right);
  return max(lh,rh);
 }
