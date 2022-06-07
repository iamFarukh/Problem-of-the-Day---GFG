TNode* solve(LNode *&head, int len){
       
       if(len<=0 || head == NULL)
        return NULL ;
        
        
       TNode *leftTree = solve(head , len/2) ;  //N/2 part of the list is left subtree tree
       
       TNode *root = new TNode(head->data) ; 
       root->left = leftTree ; 
       
       head = head->next ;
       
       root->right = solve( head , len - len/2-1) ;     //N-N/2-1 part is right subtree
       return root; 

    }

    TNode* sortedListToBST(LNode *head) {
        LNode* temp = head ; 
        int len =0 ;            //linked list length
            
        while(temp != NULL){
            len++ ; 
            temp = temp->next ;
        }  
        
        return solve(head , len) ; 
    }
