/* 
* First, I use a stack to record the route of target
* When I search the target with preorder traversal,
* I push the nodes into stack until I find the target.
* Then for each node in the stack, searching its child node which has K distance from target
*/

typedef struct node {
    struct TreeNode *tn_ptr; //store ptr for each node in tree
    struct node *prev;
} Node;

Node *getNode(struct TreeNode *tn_ptr) {
    Node *n = malloc(sizeof(Node));
    n->tn_ptr = tn_ptr;
    n->prev = NULL;
    return n; 
}

typedef struct stack {
    Node *top;
    int size;
} Stack;

Stack *getStack() {
    Stack *s = malloc(sizeof(Stack));
    s->top = NULL;
    s->size = 0;
    return s;
}

void pushStack(Stack *s, struct TreeNode *tn_ptr) {
    Node *n = getNode(tn_ptr);
    n->prev = s->top;
    s->top = n;
    s->size++;
}

Node *popStack(Stack *s) {
    Node *n = s->top;
    s->top = s->top->prev;
    s->size--;
    return n;
}

bool isEmpty(Stack *s) {
    if(!s->top)
        return true;
    return false;
}

Stack *route;
int *re;
int re_size;
bool found;


void getRoute(struct TreeNode *tn_ptr, struct TreeNode *tn_target) {
    pushStack(route, tn_ptr);
    
    if(tn_ptr->val == tn_target->val) {
        found = true;
        return;
    }
    
    if(tn_ptr->left && !found)
        getRoute(tn_ptr->left, tn_target);
    
    if(found)
        return;
    //pop
    while(route->top->tn_ptr != tn_ptr) {
        popStack(route);
    }
    
    if(tn_ptr->right && !found)
        getRoute(tn_ptr->right, tn_target);
}

void searchChild(struct TreeNode *tn, struct TreeNode *deadend, int dist) {
    if(dist < 0) return;
    if(dist == 0 && tn!= deadend) {
        re[re_size] = tn->val;
        re_size++;
        return;
    } else {
        if(tn->left && tn->left != deadend) {
            searchChild(tn->left, deadend, dist - 1);
        }
        if(tn->right && tn->right != deadend) {
            searchChild(tn->right, deadend, dist - 1);
        }
    }
}



int* distanceK(struct TreeNode* root, struct TreeNode* target, int K, int* returnSize) {

    found = false;
    route = getStack();
    getRoute(root, target);
    
    re = malloc(sizeof(int) * 500);
    re_size = 0;
    *returnSize = 0;
    
    struct TreeNode *deadend = NULL;
    while(!isEmpty(route) && K > -1) {
        Node *ptr = popStack(route);
        searchChild(ptr->tn_ptr, deadend, K);
        K--;
        deadend = ptr->tn_ptr;
    }
    
    *returnSize = re_size;
    return re;
}
