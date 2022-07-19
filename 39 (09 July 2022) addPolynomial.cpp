Node* addPolynomial(Node *p1, Node *p2)
    {
        if(!p1)  return p2;
        if(!p2)  return p1;
        
        if(p1 -> pow > p2 -> pow){
            p1 -> next = addPolynomial(p1 -> next, p2);
        return p1;
        }
        if(p1 -> pow < p2 -> pow){
                p2 -> next = addPolynomial(p1, p2 -> next);
            return p2;
        }
        else{
            p1 -> coeff += p2 -> coeff;
            p1 -> next = addPolynomial(p1 -> next, p2 -> next);
            return p1;
        }
    }
