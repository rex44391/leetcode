/*
* The algorithm itself is simple; the implementation in C is super annoying
* for example, you should cosider the case of  x, -x and 0x
* Dealing with this makes my code dirty, you can try to make it clean on your own
*/

bool not_digit(char c) {
    if(c == '+' || c == '-' || c == 'x')
        return true;
    else
        return false;
}

char* solveEquation(char* equation) {
    int left_x = 0;
    int left_val = 0;
    int right_x = 0;
    int right_val = 0;
    
    int ptr = 0;
    while(equation[ptr] != '=') {

        if(not_digit(equation[ptr])) {
            if(ptr - 1 == -1 && equation[ptr] == 'x') {
                left_x++;
                ptr++;
                continue;
            }
            int num = 0;
            int multi = 1;
            int ptr2 = ptr - 1;
            while(!not_digit(equation[ptr2]) && ptr2 >= 0){
                num += ((equation[ptr2] - '0') * multi);
                multi *= 10;
                ptr2--;
            }
            
            if(equation[ptr] == 'x') {
                if(num == 0 && equation[ptr - 1] == '0') {
                    ptr++;
                    continue;
                }
                if(num == 0) {
                    if(equation[ptr2] == '-') 
                        left_x--;
                    else
                        left_x++;
                } else {
                    if(equation[ptr2] == '-')
                        left_x -= num;
                    else
                        left_x += num;
                }
            } else {
                if(equation[ptr2] == '-') {
                    left_val -= num;
                } else {
                    left_val += num;
                }
            } 
        }
        
        ptr++;
    }

    if(equation[ptr - 1] != 'x') {
        int num = 0;
        int multi = 1;
        int ptr2 = ptr - 1;
        while(!not_digit(equation[ptr2]) && ptr2 >= 0) {
            num += ((equation[ptr2] - '0') * multi);
            multi *= 10;
            ptr2--;
        }
        if(equation[ptr2] == '-') {
            left_val -= num;
        } else {
            left_val += num;
        }
    }
    
    ptr++;
    while(equation[ptr] != '\0') {

        if(not_digit(equation[ptr])) {
            int num = 0;
            int multi = 1;
            int ptr2 = ptr - 1;
            while(!not_digit(equation[ptr2]) && equation[ptr2] != '=') {
                num += ((equation[ptr2] - '0') * multi);
                multi *= 10;
                ptr2--;
            }

            if(equation[ptr] == 'x') {
                if(num == 0 && equation[ptr - 1] == '0') {
                    ptr++;
                    continue;
                }
                if(num == 0) {
                    if(equation[ptr2] == '-')
                        right_x--;
                    else
                        right_x++;
                } else {
                    if(equation[ptr2] == '-')
                        right_x -= num;
                    else
                        right_x += num;
                }
            } else {
                if(equation[ptr2] == '-') {
                    right_val -= num;
                } else {
                    right_val += num;
                }
            }
        }
        
        ptr++;
    }
    
    if(equation[ptr - 1] != 'x') {
        int num = 0;
        int multi = 1;
        int ptr2 = ptr - 1;
        while(!not_digit(equation[ptr2]) && equation[ptr2] != '=') {
            num += ((equation[ptr2] - '0') * multi);
            multi *= 10;
            ptr2--;
        }
        if(equation[ptr2] == '-') {
            right_val -= num;
        } else {
            right_val += num;
        }
    }
    
    //cal
    right_val -= left_val;
    left_x -= right_x;
    
    if(left_x == 0) {
        if(right_val == 0)
            return "Infinite solutions";
        else
            return "No solution";
    }

    char *re = malloc(sizeof(char) * 1000);
    int re_size = 2;
    re[0] = 'x';
    re[1] = '=';
    int sol = right_val / left_x;
    
    if(sol == 0)
        return "x=0";
    
    if(sol < 0) {
        sol *= -1;
        re[re_size] = '-';
        re_size++;
    }

    char *st = malloc(sizeof(char) * 1000);
    int st_size = 0;
    while(sol > 0) {
        st[st_size] = (sol % 10) + '0';
        st_size++;
        sol /= 10;
    }
    for(int i = st_size - 1; i >= 0; i--) {
        re[re_size] = st[i];
        re_size++;
    }
    re[re_size] = '\0';
    return re;
}
