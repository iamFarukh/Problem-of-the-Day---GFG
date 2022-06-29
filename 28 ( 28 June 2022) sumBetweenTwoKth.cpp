long long KthSmall(long long v[], int n, long long k)
    {
        priority_queue<int, vector<int>> pq; // Max Heap
    
        for (int i = 0; i < k; i++)
        {
            pq.push(v[i]);
        }
    
        for (int i = k; i < n; i++)
        {
            if (v[i] < pq.top())
            {
                pq.pop();
                pq.push(v[i]);
            }
        }
        return pq.top();
    }
    
    long long sumBetweenTwoKth( long long A[], long long N, long long K1, long long K2)
    {
        // Your code goes here
        
        long long temp1 = KthSmall(A, N, K1);
        long long temp2 = KthSmall(A, N, K2);
        
       long long sum1 = 0;
        for (int i = 0; i < N; i++)
        {
            if (A[i] > temp1 && A[i] < temp2)
            {
                sum1 += A[i];
            }
        }
        return sum1;
    }
