/*
* I use preorder traveral to visit each node and write the val into a global string
* Again the algorithm is easy, but troublesome for implementation
* The stack here is to record the value of a node
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

char **re;
int re_size;
char *route;
int route_length;
Stack *s;

void recur(struct TreeNode *tn) {
    int val = tn->val;
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
        route[route_length] = popStack(s);
        route_length++;
    }
    
    int original_length = route_length;
    
    if(!tn->left && !tn->right) {
        re[re_size] = malloc(sizeof(char) * (route_length + 1) );
        for(int i = 0; i < route_length; i++) {
            re[re_size][i] = route[i];
        }
        re[re_size][route_length] = '\0';
        re_size++;
        return;
    }
    
    if(tn->left) {
        route[route_length] = '-';
        route_length++;
        route[route_length] = '>';
        route_length++;
        recur(tn->left);
    }
    route_length = original_length;
    if(tn->right) {
        route[route_length] = '-';
        route_length++;
        route[route_length] = '>';
        route_length++;
        recur(tn->right);
    }
    route_length = original_length;
}

char** binaryTreePaths(struct TreeNode* root, int* returnSize) {
    if(!root) return NULL;
    
    s = getStack();
    re = malloc(sizeof(char*) * 1000);
    re_size = 0;
    route_length = 0;
    route = malloc(sizeof(char) * 1000);
    
    recur(root);
    
    *returnSize = re_size;

    return re;
}
