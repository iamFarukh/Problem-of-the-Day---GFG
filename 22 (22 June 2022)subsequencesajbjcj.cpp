int fun(string &s) {
        long a = 0, b = 0, c = 0, m = 1e9+7;
        for(auto &i:s){
            a = i == 'a' ? (2*a+1)%m : a;
            b = i == 'b' ? (2*b+a)%m : b;
            c = i == 'c' ? (2*c+b)%m : c;
        }
        return c;
    }
