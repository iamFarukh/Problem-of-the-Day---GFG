void dfs(int& ans, int source, int dest, vector< vector<int> >& adj){
    if(source == dest){
        ans++ ;
        return ;
    }
    for(auto &x: adj[source])
        dfs(ans,x,dest,adj) ;
}

int possible_paths(vector<vector<int>>edges, int n, int s, int d){
    vector< vector<int> > adj(n) ;
    for(auto &e : edges)
        adj[e[0]].push_back(e[1]) ;
    int ans = 0 ;
    dfs(ans,s,d,adj) ;
    return ans ;
}
