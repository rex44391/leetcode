/*
* this algorithm is just using a pointer, in increment or decrement manner, 
* to figure out a character should go to which row 
* and keep a table to record each row. 
* Therefore I use lots of space here. 
* I know I can just use math to calculate the position of the return string for each character
* I will do some improvement in the future
*/

char* convert(char* s, int numRows) {
    if(numRows == 1) return s;
    char *re = malloc(sizeof(char) * 50000);
    int re_size = 0;
    
    if(numRows == 2) {
        int s_len = 0;
        while(s[s_len] != '\0') {
            if(s_len % 2 == 0) {
                re[re_size] = s[s_len];
                re_size++;
            }
            s_len++;
        }
        s_len = 0;
        while(s[s_len] != '\0') {
            if(s_len % 2 == 1){
                re[re_size] = s[s_len];
                re_size++;
            }
            s_len++;
        }
        re[re_size] = '\0';
        return re;
    }
    
    
    char **table = malloc(sizeof(char*) * numRows);
    int *size = malloc(sizeof(int) * numRows);
    for(int i = 0; i < numRows; i++) {
        table[i] = malloc(sizeof(char) * 500);
        size[i] = 0;
    }
    
    int s_len = 0;
    int order = 0;
    bool sign = true;//true:increment false:decrement
    while(s[s_len] != '\0') {
        table[order][size[order]] = s[s_len];
        size[order]++;
        if(sign) {
            order++;
            if(order >= numRows) {
                order -= 2;
                sign = false;
            }
        } else {
            order--;
            if(order < 0) {
                order += 2;
                sign = true;
            }
        }
        
        s_len++;
    }
    
    
    for(int i = 0; i < numRows; i++) {
        for(int j = 0; j < size[i]; j++) {
            re[re_size] = table[i][j];
            re_size++;
        }
    }
    re[re_size] = '\0';
    return re;
}
