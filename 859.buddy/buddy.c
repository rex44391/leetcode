/*
* just check how many different chars that A and B have.
*/

bool buddyStrings(char* A, char* B) {
    int a_len = 0;
    while(A[a_len] != '\0')
        a_len++;
        
    int b_len = 0;
    while(B[b_len] != '\0')
        b_len++;
    
    if(a_len != b_len)
        return false;
    
    int diff = 0;
    int *table = malloc(sizeof(int) * 26);
    for(int i = 0; i < 26; i++)
        table[i] = 0;
    bool flag = false;
    
    
    for(int i = 0; i < a_len; i++) {
        table[A[i] - 'a']++;
        if(table[A[i] - 'a'] > 1)
            flag = true;
        
        
        if(A[i] != B[i])
            diff++;
    }
    if(diff == 2 && !flag)
        return true;
    if(diff == 0 && flag)
        return true;
    return false;
}
