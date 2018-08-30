char* convertToBase7(int num) {
    bool flag = false;
    if(num < 0) {
        num *= -1;
        flag = true;
    }
    
    char *st = malloc(sizeof(char) * 3000);
    int st_size = 0;
    if(num == 0) {
				//if num is 0, then the algorithm will just output 
				//empty string, and has to treat it as a special case
        st[st_size] = '0';
        st_size++;
    }
    while(num > 0) {
        st[st_size] = (num % 7) + '0';
        st_size++;
        num /= 7;
    }
    if(flag) {
        st[st_size] = '-';
        st_size++;
    }
    
    char *re = malloc(sizeof(char) * 3000);
    int re_size = 0;
    for(int i = st_size - 1; i >= 0; i--) {
        re[re_size] = st[i];
        re_size++;
    }
    re[re_size] = '\0';
    return re;
}
