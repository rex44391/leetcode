

int* shortestToChar(char* S, char C, int* returnSize) {
    int s_len = 0;
    int *re = malloc(sizeof(int) * 10001);
    for(int i = 0; i < 10001; i++) {
        re[i] = INT_MAX;
    }
    
    int left = -1;
    
    while(S[s_len] != '\0') {
        
        
        if(S[s_len] == C) {
            re[s_len] = 0;
            
            if(left == -1) {
                int dist = 1;
                for(int i = s_len - 1; i >= 0; i--) {
                    re[i] = dist;
                    dist++;
                }
                left = s_len;
            } else {
                int left_ptr = left + 1;
                int right_ptr = s_len - 1;
                int dist = 1;
                while(left_ptr <= right_ptr) {
                    re[left_ptr] = dist;
                    re[right_ptr] = dist;
                    left_ptr++;
                    right_ptr--;
                    dist++;
                }
                left = s_len;
            }
            
        }
        s_len++;
    }
    
    if(re[s_len - 1] != 0) {
        int dist = 1;
        for(int i = left + 1; i < s_len; i++) {
            re[i] = dist;
            dist++;
        }
    }
    
    *returnSize = s_len;
    return re;
}
