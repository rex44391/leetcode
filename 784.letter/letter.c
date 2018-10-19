/*
* for the first character in S,
* if it's a digit, we create one new string whose first and only element is the digit.
* if it's an alphabet, say c, we create two new string "c" and "C".
* And for the remaining characters in S, 
* when we encounter a digit, we append that digit to all the strings we have created
* if it's not a number, we first create new strings by copy the strings we already have, and append lower case to the original part of strings and upper case to new one.
*/

char** letterCasePermutation(char* S, int* returnSize) {
    char **re = malloc(sizeof(char *) * 5000);
    for(int i = 0; i < 5000; i++) {
        re[i] = malloc(sizeof(char) * 13);
    }
    
    int re_size = 0;
    
    int s_len = 0;
    
    if(S[s_len] == '\0') {
        re[0] = "";
        *returnSize = 1;
        return re;
    }
    
    if((S[s_len] - '0' >= 0) &&  (S[s_len] - '0' <= 9)) {
        re[re_size][s_len] = S[s_len];
        re_size++;
    } else {
        re[re_size][s_len] = tolower(S[s_len]);
        re_size++;
        re[re_size][s_len] = toupper(S[s_len]);
        re_size++;
    }
    s_len++;
    
    while(S[s_len] != '\0') {
        if( (S[s_len] - '0' >= 0) &&  (S[s_len] - '0' <= 9) ) {
            for(int i = 0; i < re_size; i++) {
                re[i][s_len] = S[s_len];
            }
        } else {
            for(int i = 0; i < re_size; i++) {
                for(int j = 0; j < s_len; j++) {
                    re[re_size + i][j] = re[i][j];
                }
            }
            for(int i = 0; i < re_size; i++) {
                re[i][s_len] = tolower(S[s_len]);
                re[i + re_size][s_len] = toupper(S[s_len]);
            }
            re_size *= 2;
        }
        s_len++;
    }
    for(int i = 0; i <  re_size; i++) {
        re[i][s_len] = '\0';
    }
    *returnSize = re_size;
    return re;
}
