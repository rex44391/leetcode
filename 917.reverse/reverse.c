/*
* beats 100%
*/

bool isAlpha(char c) {
    if( (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return true;
    return false;
}

char* reverseOnlyLetters(char* S) {
    if(!S || S == "") return NULL;
    int s_len = 0;
    char *re = malloc(sizeof(char) * 110);
    for(int i = 0; i < 110; i++)
        re[i] = 'a';
    
    
    int re_len = 0;
    while(S[s_len] != '\0') {
        if( !isAlpha(S[s_len])) {
            re[re_len] = S[s_len];
        }
        re_len++;
        s_len++;
    }
    
    int s_ptr = s_len - 1;
    re_len = 0;
    while(s_ptr != -1) {
        while(s_ptr >= 0 && !isAlpha(S[s_ptr]))
            s_ptr--;
        while((re_len < s_len) && !isAlpha(re[re_len]))
            re_len++;
        
        if(s_ptr < 0 || re_len >= s_len)
            break;
        
        re[re_len] = S[s_ptr];
        re_len++;
        s_ptr--;
    }
    
    re_len = s_len;
    re[re_len] = '\0';
    return re;
}
