int minColour(int N, int M, vector<int> mat[]) {
        vector <int> adj[N+1], in(N+1);
        
        for(int i=0; i<M; i++){
            int u = mat[i][0], v = mat[i][1];
            adj[u].push_back(v);
            
            in[v]++;
        }
        
        queue <int> q;
        vector <int> dep(N+1, -1);
        
        for(int i=1; i<=N; i++){
            if(in[i] == 0){
                q.push(i);
                dep[i] = 1;
            }
        }
        
        while(!q.empty()){
            int v = q.front();
            q.pop();
            
            for(auto& u : adj[v]){
                in[u]--;
                dep[u] = max(dep[u], 1 + dep[v]);
                if(in[u] == 0){
                    q.push(u);
                }
            }
        }
        
        int ans = 1;
        for(int i=1; i<=N; i++){
            ans = max(ans, dep[i]);
        }
        
        return ans;
    }
