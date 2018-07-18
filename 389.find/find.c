/*
* This algorithm is nothing special, 
* I just sort s and t first, and find the first characters of the two strings that don't match with each other 
*/


int cmpfunc (const void * a, const void * b) {
   return ( *(char*)a - *(char*)b );
}

char findTheDifference(char* s, char* t) {
    int s_len = 0;
    int t_len = 0;
    while(s[s_len] != '\0')
        s_len++;
    
    
    qsort(s, s_len, sizeof(char), cmpfunc);
    qsort(t, s_len + 1, sizeof(char), cmpfunc);
    for(int i = 0; i < s_len; i++) {
        if(s[i] != t[i])
            return t[i];
    }
    return t[s_len];
}
