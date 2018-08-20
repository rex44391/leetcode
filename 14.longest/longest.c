/*
* a straight forward algorithm, just same as your first thought in this problem
*/

char* longestCommonPrefix(char** strs, int strsSize) {
    char *re = malloc(sizeof(char) * 2000);
    int size = 0;
    int ptr = 0;
    while(true) {
        bool flag = true;
        char temp = strs[0][ptr];
        if(temp == '\0') {
            break;
        }
        for(int i = 1; i < strsSize; i++) {
            if(strs[i][ptr] == '\0' || strs[i][ptr] != temp) {
                flag = false;
                break;
            }
        }
        if(flag) {
            re[size] = strs[0][ptr];
            size++;
        } else {
            break;
        }
        ptr++;
    }
    re[size] = '\0';
    size++;
    return re;
}
