typedef struct node {
    int val;
    int level;
    struct node *prev;
} Node;

Node *getNode(int val, int level) {
    Node *n = (Node *)malloc(sizeof(Node));
    n->val = val;
    n->level = level;
    return n;
}

typedef struct stack {
    Node *top;
} Stack;

Stack *getStack() {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->top = NULL;
    return s;
}


void pushStack(Stack *s, int val, int level) {
    Node *n = getNode(val, level);
    n->prev = s->top;
    s->top = n;
}

Node *popStack(Stack *s) {
    Node *n = s->top;
    s->top = s->top->prev;
    return n;
}

bool isEmpty(Stack *s) {
    if(!s->top)
        return true;
    else
        return false;
}

Stack *s;
int max_level;

void inOrder(struct TreeNode *tn, int level) {
    if(level > max_level)
        max_level = level;
    
    if(tn->left)
        inOrder(tn->left, level+1);
    
    pushStack(s, tn->val, level);
    
    if(tn->right)
        inOrder(tn->right, level+1);
}


int* rightSideView(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    if(!root) return NULL;
    
    s = getStack();
    max_level = -1;
    
    inOrder(root, 0);
    
    *returnSize = max_level + 1;
    bool *check = (bool*)malloc(sizeof(bool) * (max_level+1) );
    for(int i = 0; i < max_level + 1; i++)
        check[i] = false;
    int *re = (int*)malloc(sizeof(int) * (max_level+1) );
    
    while(!isEmpty(s)) {
        Node *n = popStack(s);
        if(!check[n->level]) {
            check[n->level] = true;
            re[n->level] = n->val;
        }
    }
    
    return re;
}
