/*
* beats 100%, using recursive way(although implementing in iterative way) to solve this
*/

char *re;
int re_size;

char* getPermutation(int n, int k) {
    re = malloc(sizeof(char) * 10);
    re_size = 0;
    int *cand = malloc(sizeof(int) * n);
    int cand_size = n;
    
    for(int i = 0; i < cand_size; i++)
        cand[i] = i + 1;
    
    int fact = 1;
    for(int i = 1; i < n; i++)
        fact *= i;
    int fact_ptr = n - 1;
    if(k == 0 || k > (fact * n) ) return;
    
    k--;
    
    while(re_size < n ) {
        int pos = k / fact;
        
        k %= fact;
        re[re_size] = cand[pos] + '0';
        
        int *new_cand = malloc(sizeof(int) * (cand_size - 1));
        int ptr = 0;
        for(int i = 0; i < cand_size; i++) {
            if(i == pos)
                continue;
            new_cand[ptr] = cand[i];
            ptr++;
        }
        
        cand = new_cand;
        cand_size--;
        
        if(fact_ptr > 0)
            fact /= fact_ptr;
        fact_ptr--;
        re_size++;
    }
    re[re_size] = '\0';
    return re;
}
