//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};


// } Driver Code Ends
//User function Template for C++

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution
{
public:
// Converting doubly linkedlist to vector

   vector<int> changing(Node *head){
       
       vector<int> v;
       
       while(head !=NULL){
           v.push_back(head->data);
           head=head->next;
       }
       
       return v;
   }

   vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
   {
       vector<int> v = changing(head);
      
       vector<pair<int,int>> res;
       
       // Declaring unordered Set
       unordered_set<int> s;
       
       for(int i=0;i<v.size();i++){
           
           // Declaring pair
           pair <int,int> p; 
           
           // Declaring pair value as NULL
           p.first=NULL;
           p.second=NULL;
           
           // if target-v[i] is present then initialize first = target-v[i] and second = v[i] else insert v[i]
           // to the unorderedset
           if(s.count(target - v[i])){
               p.first = target-v[i];
               p.second = v[i];
           }else{
               s.insert(v[i]);
           }
           
           // checking whether pair is empty or not
           if(p.first != NULL && p.second !=NULL){
               res.push_back(p);
           }
       }
   
       reverse(res.begin(),res.end());
       
       return res;
   }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, target;
        cin >> target >> n;
        int a;
        cin >> a;
        Node *head = new Node(a);
        Node *tail = head;
        for (int i = 0; i < n - 1; i++)
        {
            cin >> a;
            tail->next = new Node(a);
            tail->next->prev = tail;
            tail = tail->next;
        }
        Solution ob;
        auto ans = ob.findPairsWithGivenSum(head, target);
        if (ans.size() == 0)
            cout << "-1";
        else
        {
            for (int i = 0; i < ans.size(); i++)
            {
                cout << "(" << ans[i].first << "," << ans[i].second << ")"
                     << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
