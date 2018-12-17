/*
* using a table to record the lexical order of each alphabet
* then use the table to check the order
*/

bool isAlienSorted(char** words, int wordsSize, char* order) {
    int *table = malloc(sizeof(int) * 26);
    int s_len = 0;
    while(order[s_len] != '\0') {
        table[order[s_len] - 'a'] = s_len;
        s_len += 1;
    }

    for(int i = 0; i < wordsSize - 1; i++) {
				//need to do some works here to check whether the two strings
				// i and i + 1 in words array meet the lexical order
        int pointer = 0;
        bool flag = false;
        while(words[i][pointer] != '\0' && words[i+1][pointer] != '\0') {
            //printf("%c, %c\n", words[i][pointer],  words[i+1][pointer]);
            if(table[words[i][pointer] - 'a'] < table[words[i+1][pointer] - 'a']) {
                flag = true;
                break;
            } else if (table[words[i][pointer] - 'a'] > table[words[i+1][pointer] - 'a']) {
                return false;
            }
            pointer += 1;
        }
        if(words[i][pointer] != '\0' && words[i+1][pointer] == '\0')
            return false;
        if(flag) {
            continue;
        }
    }
    return true;
}
