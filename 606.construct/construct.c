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
    Node *n = s->top;
    s->top = s->top->prev;
    free(n);
    return re;
}

bool isEmpty(Stack *s) {
    if(!s->top)
        return true;
    return false;
}


char *re;
int re_ptr;
Stack *s;

void recur(struct TreeNode *tn) {
    int val = tn->val;
    while(!isEmpty(s)) {
        popStack(s);
    }
    if(val < 0) {
        val = -1 * val;
        while(val > 0) {
            pushStack(s, (val % 10) + '0');
            val /= 10;
        }
        pushStack(s, '-');
    } else if(val == 0) {
        pushStack(s, '0');
    } else {
        while(val > 0) {
            pushStack(s, (val % 10) + '0');
            val /= 10;
        }
    }
    
    
    while(!isEmpty(s)) {
        re[re_ptr] = popStack(s);
        re_ptr++;
    }
    
    if(!tn->left && !tn->right)
        return;
    
    
    re[re_ptr] = '(';
    re_ptr++;
    
    if(tn->left) {
        recur(tn->left);
    }
    

    re[re_ptr] = ')';
    re_ptr++;
    
    if(tn->right) {
        re[re_ptr] = '(';
        re_ptr++;
        recur(tn->right);
        re[re_ptr] = ')';
        re_ptr++;
    }
}


char* tree2str(struct TreeNode* t) {
    if(!t) return "";
    
    
    re = malloc(sizeof(char) * 50000);
    re_ptr = 0;
    s = getStack();
    recur(t);
    
    re[re_ptr] = '\0';
    return re;
}
