

int countBinarySubstrings(char* s) {
    if(!s) return 0;
    int s_len = 0;
    while(s[s_len] != '\0')
        s_len += 1;
    int re = 0;
    
    for(int i = 0; i < s_len - 1; i++) {//i is start point
        int f_counter = 1;
        int ptr = i + 1;
        
        while(ptr < s_len && s[ptr] == s[i]) {
            f_counter += 1;
            ptr += 1;
        }
        
        if(ptr == s_len)
            continue;
        
        int s_counter = 1;
        int j = ptr;
        ptr += 1;
        while(ptr < s_len && s[ptr] == s[j] && s_counter < f_counter) {
            s_counter += 1;
            ptr += 1;
        }
        
        re += s_counter;
        i = j - 1;
    }
    
    
    return re;
}
