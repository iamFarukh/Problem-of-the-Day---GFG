//{ Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void append(struct Node** head_ref, struct Node **tail_ref,
            int new_data)
{
    struct Node* new_node = new Node(new_data);
    
    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

/* Function to get the middle of the linked list*/
int maxPalindrome(Node *);


/* Driver program to test above function*/
int main()
{
    int T,n,l;
    cin>>T;

    while(T--)
    {
        struct Node *head = NULL,  *tail = NULL;

        cin>>n;
        for (int i=1; i<=n; i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }
      

       cout << maxPalindrome(head)<<endl;
    }
    return 0;
}



// } Driver Code Ends


/* The Node is defined 
  /* Link list Node
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/

/*The function below returns an int denoting
the length of the longest palindrome list. */
int rec(Node *first,Node *second,int cnt)
{
    if(first==NULL || second==NULL || first->data!=second->data)
    return cnt;
    return rec(first->next,second->next,cnt+1);
}
int maxPalindrome(Node *head)
{
    Node *prev=NULL;
    Node *current=head;
    int maxlen=1;
    while(current!=NULL)
    {
        Node *next=current->next;
        current->next=prev;
        maxlen=max(maxlen,2*rec(current,next,0));
        maxlen=max(maxlen,2*rec(prev,next,0)+1);
        prev=current;
        current=next;
        
    }
    return maxlen;
    //Your code here
}
