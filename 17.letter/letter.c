char** letterCombinations(char* digits, int* returnSize) {
    char **table = malloc(sizeof(char*) * 10);
    table[2] = "abc";
    table[3] = "def";
    table[4] = "ghi";
    table[5] = "jkl";
    table[6] = "mno";
    table[7] = "pqrs";
    table[8] = "tuv";
    table[9] = "wxyz";
    
    char **re = malloc(sizeof(char*) * 5000);
    for(int i = 0; i < 5000; i++)
        re[i] = malloc(sizeof(char) * 15);
    int re_size = 0;
    
    int d_len = 0;
    if(digits[d_len] == '\0')
        return NULL;
    
    int ta_len = 3;//for table's length
    if(digits[d_len] == '7' || digits[d_len] == '9')
        ta_len = 4;
    for(int i = 0; i < ta_len; i++) {
        re[re_size][d_len] = table[digits[d_len] - '0'][i];
        re_size++;
    }
    d_len++;
    
    
    while(digits[d_len] != '\0') {
        ta_len = 3;
        if(digits[d_len] == '7' || digits[d_len] == '9')
            ta_len = 4;
        //copy
        for(int i = 0; i < re_size; i++) {
            for(int j = 0; j < d_len; j++) {
                int temp = re[i][j];
                for(int multi = 1; multi < ta_len; multi++) {
                    re[( (re_size * multi) + i)][j] = temp;
                }
            }
        }
        
        //add new
        for(int i = 0; i < ta_len; i++) {
            for(int j = 0; j < re_size; j++) {
                re[(i * re_size) + j][d_len] = table[digits[d_len] - '0'][i];
            }  
        }
        re_size *= ta_len;
        d_len++;
    }
    for(int i = 0; i < re_size; i++) {
        re[i][d_len] = '\0';
    }
    
    *returnSize = re_size;
    return re;
}
