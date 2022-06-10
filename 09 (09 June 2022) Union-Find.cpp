public:
    //Function to merge two nodes a and b.
    void union_( int a, int b, int par[], int rank[]) 
    {
        //code here
        a = whoisParent(a,par);
        b = whoisParent(b,par);
        
        if(rank[a]< rank[b])
            par[a]=b;
        else if(rank[b] < rank[a])
            par[b]=a;
        else{
            par[a]=b;
            rank[b]++;
        }
    }
    
    int whoisParent(int ele, int par[]){
        if(par[ele] == ele){
            return ele;
        }
        return par[ele] = whoisParent(par[ele],par);
    }
    //Function to check whether 2 nodes are connected or not.
    bool isConnected(int x,int y, int par[], int rank1[])
    {
        //code here
        return whoisParent(x,par)==whoisParent(y,par);
    }
