

int titleToNumber(char* s) {
    int s_len = 0;
    while(s[s_len] != '\0') {
        s_len++;
    }
    
    int multi = 1;
    int counter = 0;
    for(int i = s_len - 1; i >= 0; i--) {
        counter += (s[i] - 'A' + 1) * multi;
        multi *= 26;
    }
    return counter;
}
