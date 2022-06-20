class Solution
{
   public:
   Node* reverseBetween(Node* head, int m, int n)
   {
       vector<int>v;
       Node* a=head;
       while(a)
       {
           v.push_back(a->data);
           a=a->next;
       }
       Node* b=new Node(-1);
       a=b;
       int i;
       for(i=0;i<m-1;i++)
       {
           b->next=new Node(v[i]);
           b=b->next;
       }
       for(i=n-1;i>=m-1;i--)
       {
           b->next=new Node(v[i]);
           b=b->next;
       }
       for(i=n;i<v.size();i++)
       {
           b->next=new Node(v[i]);
           b=b->next;
       }
       return a->next;
   }
};
