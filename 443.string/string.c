/* O(n) time and O(c) space complexity
* the algorithm itself is not difficult, but a little bit troublesome to implement it
*/

typedef struct node {
    char c;
    struct node *prev;
} Node;

Node *getNode(char c) {
    Node *n = malloc(sizeof(Node));
    n->c = c;
    n->prev = NULL;
    return n;
}

typedef struct stack {
    Node *top;
} Stack;

Stack *getStack() {
    Stack *s = malloc(sizeof(s));
    s->top = NULL;
    return s;
}

void pushStack(Stack *s, char c) {
    Node *n = getNode(c);
    n->c = c;
    n->prev = s->top;
    s->top = n;
}

char popStack(Stack *s) {
    char re = s->top->c;
    s->top = s->top->prev;
    return re;
}

bool isEmpty(Stack *s) {
    if(!s->top)
        return true;
    return false;
}

int compress(char* chars, int charsSize) {
    if(charsSize == 0) return 0;
    if(charsSize == 1) return 1;
    
    Stack *s = getStack();
    
    char prev = chars[0];
    int prev_counter = 1;
    int re_ptr = 0;
    for(int i = 1; i < charsSize; i++) {
        if(chars[i] != prev) {
            //write in
            chars[re_ptr] = prev;
            re_ptr++;
            
            if(prev_counter > 1) {
                while(prev_counter > 0) {
                    pushStack(s, (prev_counter % 10) + '0');
                    prev_counter /= 10;
                }
                while(!isEmpty(s)) {
                    chars[re_ptr] = popStack(s);
                    re_ptr++;
                }
            }
            
            //reset
            prev = chars[i];
            prev_counter = 1;
        } else {
            prev_counter++;
        }
    }
    chars[re_ptr] = prev;
    re_ptr++;
    
    if(prev_counter > 1) {
        
        while(prev_counter > 0) {
            pushStack(s, (prev_counter % 10) + '0');
            prev_counter /= 10;
        }
        while(!isEmpty(s)) {
            chars[re_ptr] = popStack(s);
            
            re_ptr++;
        }
    }
    
    return re_ptr;
}
