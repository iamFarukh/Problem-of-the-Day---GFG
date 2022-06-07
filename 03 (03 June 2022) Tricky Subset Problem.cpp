int isPossible(long long S, long long N, long long X, long long A[]){
        vector<long long> vec;
        vec.push_back(S);
        long long sum=S;
        for(int i=1;i<=N && sum<=X;i++){
            vec.push_back(sum+A[i-1]);
            sum+=vec[i];
        }
        N=vec.size();
        long long itr=lower_bound(vec.begin(),vec.end(),X)-vec.begin();
        for(int i=itr;i>=0;i--){
            if(vec[i]<=X){
                X-=vec[i];
            }
            if(X==0){
                return 1;
            }
        }
        return 0;
    }
