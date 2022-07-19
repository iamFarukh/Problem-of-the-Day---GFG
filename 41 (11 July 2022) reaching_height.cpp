vector<int> reaching_height(int n, int a[]) {
   // Complete the function
   
   sort( a , a+n ) ;
   vector<int>odd ;
   vector<int>even ;
   int i = 0 ;
   for( i = 0 ; i<n/2 ; i++)
   {
       even.push_back(a[i]) ;
   }
   
   for( i = n-1 ; i>=n/2 ; i-- )
   {
       odd.push_back(a[i]) ;
   }
   
   set<int>st( a , a+n ) ;
   if(st.size() == 1 && n != 1) return { -1 } ;
   
   vector<int>v(n) ;
   int c1 = 0 , c2 = 0 ;
   for( int i = 0 ; i<n ; i++)
   {
       if(i%2==0)
       {
           v[i] = odd[c1] ;
           c1++ ;
       }
       else{
           v[i] = even[c2] ;
           c2++ ;
       }
   }
   
   return v ;
}
