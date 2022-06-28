void helper(int level,int pos,bool &ans){
       if(pos==0){return;}
       helper(level,(pos>>1),ans);
       if(pos&1){
           ans=!ans;
       }
   }
   char profession(int level, int pos){
       bool ans=true;
       helper(level,(pos-1),ans);
       if(ans)return 'e';
       else return 'd';
   }
