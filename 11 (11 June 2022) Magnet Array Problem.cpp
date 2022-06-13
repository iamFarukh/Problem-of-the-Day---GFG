void nullPoints(int n, double magnets[], double getAnswer[])
    {
        // Your code goes here   
        for(int i =0;i<n-1;i++){
            getAnswer[i] = zeroForce(magnets[i], magnets[i+1],magnets,n);
        }
        
        
    }
    double zeroForce(double low, double high, double  magnets[],int n){
        
        while(low<high){
            double mid = (low+high)/2;
            double ans = 0  ;
            for(int i =0;i<n;i++){
                ans += 1/(mid-magnets[i]);
            }
            if(abs(ans) <0.000001){
                return mid;
            }
            if(ans<0){
                high = mid;
            }
            else{
                low = mid;
            }
            
        }
        return low;
    }
