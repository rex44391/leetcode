/*
* It is known to use a stack to check the validity of the parentheses.
* So to solve this problem, I use a counter(named s_counter) to simulate the behavior of a stack.
*/

int minAddToMakeValid(char* S) {
    int s_counter = 0;
    int counter = 0;
    
    int ptr = 0;
    while(S[ptr] != '\0') {
        if(S[ptr] == ')') {
            s_counter--;
        } else {
            s_counter++;
        }
        if(s_counter == -1) {
            s_counter = 0;
            counter++;
        }
        ptr++;
    }
    
    if(s_counter > 0) {
        counter += s_counter;
    }
    
    return counter;
}
