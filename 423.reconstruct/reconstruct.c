/*
* the concept of this is easy, just write down all the digits'
* English spelling, and look for their unique features.
* for example, only zero has z in its spelling.
*/

char* originalDigits(char* s) {
    int *table = malloc(sizeof(int) * 26);
		//recording the frequency of each character
    for(int i = 0; i < 26; i++) 
        table[i] = 0;
    
    int s_len = 0;
    while(s[s_len] != '\0') {
        table[s[s_len] - 'a'] += 1;
        s_len++;
    }
    
    int *digit_table = malloc(sizeof(int) * 10);
    
    //get zero
    //printf("%d\n", table['z' - 'a']);
    digit_table[0] = table['z' - 'a'];
    table['e' - 'a'] -= table['z' - 'a'];
    table['r' - 'a'] -= table['z' - 'a'];
    table['o' - 'a'] -= table['z' - 'a'];
    table['z' - 'a'] = 0;
		//we check how many z in s
		//then we know how many zero in s
		//and we update the table
		//to figure out other digits' frequency
    
    //get two
    digit_table[2] = table['w' - 'a'];
    table['t' - 'a'] -= table['w' - 'a'];
    table['o' - 'a'] -= table['w' - 'a'];
    table['w' - 'a'] = 0;
    
    //get six
    digit_table[6] = table['x' - 'a'];
    table['s' - 'a'] -= table['x' - 'a'];
    table['i' - 'a'] -= table['x' - 'a'];
    table['x' - 'a'] = 0;
    
    //get eight
    digit_table[8] = table['g' - 'a'];
    table['e' - 'a'] -= table['g' - 'a'];
    table['i' - 'a'] -= table['g' - 'a'];
    table['h' - 'a'] -= table['g' - 'a'];
    table['t' - 'a'] -= table['g' - 'a'];
    table['g' - 'a'] = 0;
    
    //get seven
    digit_table[7] = table['s' - 'a'];
    table['e' - 'a'] -= (table['s' - 'a'] * 2);
    table['v' - 'a'] -= table['s' - 'a'];
    table['n' - 'a'] -= table['s' - 'a'];
    table['s' - 'a'] = 0;
    
    //get five
    digit_table[5] = table['v' - 'a'];
    table['f' - 'a'] -= table['v' - 'a'];
    table['i' - 'a'] -= table['v' - 'a'];
    table['e' - 'a'] -= table['v' - 'a'];
    table['v' - 'a'] = 0;
    
    //get four
    digit_table[4] = table['f' - 'a'];
    table['o' - 'a'] -= table['f' - 'a'];
    table['u' - 'a'] -= table['f' - 'a'];
    table['r' - 'a'] -= table['f' - 'a'];
    table['f' - 'a'] = 0;
    
    //get one
    digit_table[1] = table['o' - 'a'];
    table['n' - 'a'] -= table['o' - 'a'];
    table['e' - 'a'] -= table['o' - 'a'];
    table['o' - 'a'] = 0;
    
    //get three
    digit_table[3] = table['t' - 'a'];
    table['e' - 'a'] -= (table['t' - 'a'] * 2);
    table['h' - 'a'] -= table['t' - 'a'];
    table['r' - 'a'] -= table['t' - 'a'];
    table['t' - 'a'] = 0;
    
    //get nine
    digit_table[9] = table['i' - 'a'];
    
		//after we know all the frequency of the digits
		//we just write into a string for returning
    char *re = malloc(sizeof(char) * 50000);
    int re_len = 0;
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < digit_table[i]; j++) {
            re[re_len] = i + '0';
            re_len += 1;
        }
    }
    re[re_len] = '\0';
    return re;
}
