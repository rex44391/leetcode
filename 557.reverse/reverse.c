char* reverseWords(char* s) {
    char *copy = malloc(sizeof(char) * 50000);
    int c_size = 0;
    int size = 0;
    
    char *temp = malloc(sizeof(char) * 50000);
    int t_size = 0;
    while(s[size] != '\0') {
        if(s[size] == ' ') {
            //copy temp to copy            
            for(int i = 0; i < t_size; i++) {
                copy[c_size] = temp[t_size - i - 1];
                c_size++;
            }
            copy[c_size] = ' ';
            c_size++;
                        
            //reset temp
            t_size = 0;
        } else {
            temp[t_size] = s[size];
            t_size++;
        }
        size++;
    }
    if(t_size > 0) {
        for(int i = 0; i < t_size; i++) {
            copy[c_size] = temp[t_size - i - 1];
            c_size++;
        }
    }
    copy[c_size] = '\0';
    return copy;
}
