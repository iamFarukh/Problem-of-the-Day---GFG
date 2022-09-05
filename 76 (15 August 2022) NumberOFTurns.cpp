//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
      
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
          
        // Get the current node's value from the string
        string currVal = ip[i];
          
        // If the left child is not null
        if(currVal != "N") {
            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }
          
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
          
        // If the right child is not null
        if(currVal != "N") {
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function template for C++
/*
Structure of the node of the tree is as follows 
struct Node {
    struct Node* left, *right;
    int data;
};
*/

class Solution{
  public:
    // function should return the number of turns required to go from first node to second node 
    Node* lca(Node* root,int a,int b){
        if(root==NULL){
            return NULL;
        }
        Node* l=lca(root->left,a,b);
        Node* r=lca(root->right,a,b);
        if(root->data==a || root->data==b){
            return root;
        }
        if(l!=NULL && r!=NULL){
            return root;
        }
        else if(l!=NULL){
            return l;
        }
        else if(r!=NULL){
            return r;
        }
        return NULL;
    }
    int dfs(Node* _lca,int a,int side,int &turns){
        if(_lca==NULL){
            return 0;
        }
        if(_lca->data==a){
            return 1;
        }
        int l=dfs(_lca->left,a,-1,turns);
        int r=dfs(_lca->right,a,1,turns);
        if(l==1 && side==1){
            turns++;
            return 1;
        }
        else if(r==1 && side==-1){
            turns++;
            return 1;
        }
        return max(l,r);
    }
    int NumberOFTurns(struct Node* root, int first, int second)
    {
      // Your code goes here
      int turns=0;
      Node* LCA=lca(root,first,second);
      dfs(LCA,first,0,turns);
      dfs(LCA,second,0,turns);
      if(first!=LCA->data && second!=LCA->data){
          turns++;
      }
      return turns;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    struct Node *child;
    scanf("%d ", &t);
    while (t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        int turn, first, second;
        cin>>first>>second;
        Solution ob;
        if ((turn = ob.NumberOFTurns(root, first, second) ))
            cout<<turn<<endl;
        else 
            cout<<"-1\n";
        cin.ignore();
    }
    return 0;
}

// } Driver Code Ends
