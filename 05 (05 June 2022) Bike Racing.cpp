long buzzTime(long n, long M, long L, long H[], long A[]) {
        
        int l = 0, h = 1e8;
        int ans = 0;
        while(l <= h) {
            int mid = l + (h - l) / 2;
            
            long long speed = 0;
            for(int i = 0; i < n; i++) {
                long sp = H[i] + (mid * A[i]);
                if(sp >= L) speed += sp;
            }
            
            if(speed >= M) {
                ans = mid;
                h = mid - 1;
            }
            else l = mid + 1;
        }
        return ans;
    }
