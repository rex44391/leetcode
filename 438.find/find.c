/*
* counting sort + sliding window
* beats other 100% submissions
*/

int* findAnagrams(char* s, char* p, int* returnSize) {
    if(!s || !p) return NULL;
    
    int *table = malloc(sizeof(int) * 26);
    for(int i = 0; i < 26; i++)
        table[i] = 0;
    
    int *re = malloc(sizeof(int) * 50000);
    int re_size = 0;
    
    int neg_sum = 0;
    int pos_sum = 0;
    int p_len = 0;
    while(p[p_len] != '\0') {//check p's alphabet count
        int pos = p[p_len] - 'a';
        table[pos]++;
        pos_sum++;
        p_len++;
    }
    
    int s_len = 0;
    while(s[s_len] != '\0') {
        //get s's length, make my life easier
        s_len++;
    }
    
    if(s_len < p_len) return NULL;
    
    for(int i = 0; i < p_len; i++) {//check first window
        int pos = s[i] - 'a';
        if(table[pos] > 0) {
            pos_sum--;
        } else {
            neg_sum++;
        }
        table[pos]--;
    }
    if(neg_sum == 0 && pos_sum == 0) {
        re[re_size] = 0;
        re_size++;
    }
    
    for(int i = 1; i <= s_len - p_len; i++) {
        //update exit
        int pos = s[i - 1] - 'a';
        if(table[pos] >= 0) {
            pos_sum++;
        } else {
            neg_sum--;
        }
        table[pos]++;
        //update enter
        pos = s[i + p_len - 1] - 'a';
        if(table[pos] > 0) {
            pos_sum--;
        } else {
            neg_sum++;
        }
        table[pos]--;
        
        if(pos_sum == 0 && neg_sum == 0) {
            re[re_size] = i;
            re_size++;
        }
    }
    
    
    *returnSize = re_size;
    return re;
}
