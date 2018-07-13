typedef struct node {
    int val;
    struct node *prev;
} Node;

Node *getNode(int val) {
    Node *n = malloc(sizeof(Node));
    n->val = val;
    n->prev = NULL;
    return n;
}

typedef struct stack {
    Node *top;
} Stack;

Stack *getStack() {
    Stack *s = malloc(sizeof(Stack));
    s->top = NULL;
    return s;
}

void pushStack(Stack *s, int val) {
    Node *n = getNode(val);
    n->prev = s->top;
    s->top = n;
}

int popStack(Stack *s) {
    int re = s->top->val;
    s->top = s->top->prev;
    return re;
}

bool isEmpty(Stack *s) {
    if(!s->top)
        return true;
    else
        return false;
}

Stack *s;

void inOrder(struct TreeNode* tn) {
    if(tn->left)
        inOrder(tn->left);
    pushStack(s, tn->val);
    if(tn->right)
        inOrder(tn->right);
}

bool isValidBST(struct TreeNode* root) {
    if(!root) return true;
    s = getStack();
    inOrder(root);
    
    int ptr = popStack(s);
    while(!isEmpty(s)) {
        int ptr1 = popStack(s);
        if(ptr1 >=  ptr) {
            return false;
        }
        ptr = ptr1;
    }
    return true;
}
