class Solution{
public:
    long posIntSol(string s)
    {
         int n=0,r=0;
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='+')
             r++;
            if(s[i]=='=')
            {
                n=stoll(s.substr(i+1));
            }
        }
        r++;
        
        n=n-1;
        r=r-1;
    long long val1=1,val2=1;
    
    for(long long i=n;i>n-r;i--)
    val1*=i;
    for(long long i=1;i<=r;i++)
    val2*=i;
    
     return val1/val2;
    }
};
