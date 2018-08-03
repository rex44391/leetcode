


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
    return false;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    if(!l1 && !l2) return NULL;
    Stack *s1 = getStack();
    Stack *s2 = getStack();
    Stack *s3 = getStack();
    struct ListNode *ptr1 = l1;
    struct ListNode *ptr2 = l2;
    while(ptr1) {
        pushStack(s1, ptr1->val);
        ptr1 = ptr1->next;
    }
    while(ptr2) {
        pushStack(s2, ptr2->val);
        ptr2 = ptr2->next;
    }
    
    
    int carry = 0;
    while(true) {
        if(isEmpty(s1) && isEmpty(s2) && carry == 0) {
            break;
        }
        int temp1 = 0;
        int temp2 = 0;
        if(!isEmpty(s1)) {
            temp1 += popStack(s1);
        }
        if(!isEmpty(s2)) {
            temp2 += popStack(s2);
        }
        
        
        temp1 += temp2 + carry;
        pushStack(s3, temp1 % 10);
        
        carry = temp1 / 10;
        
    }
    struct ListNode *re_head;
    struct ListNode **pptr = &re_head;
    while(!isEmpty(s3)) {
        (*pptr) = malloc(sizeof(struct ListNode));
        (*pptr)->val = popStack(s3);
        (*pptr)->next = NULL;
        pptr = &((*pptr)->next);
    }
    
    return re_head;
}
