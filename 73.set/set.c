typedef struct node {
    int row;
    int col;
    struct node *prev;
} Node;

Node *getNode(int row, int col) {
    Node *n = (Node*)malloc(sizeof(Node));
    n->row = row;
    n->col = col;
    n->prev = NULL;
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

void pushStack(Stack *s, int row, int col) {
    Node *n = getNode(row, col);
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
    return false;
}


void setZeroes(int** matrix, int matrixRowSize, int matrixColSize) {
    if(matrixRowSize == 0 || matrixColSize == 0) return NULL;
    
    Stack *s = getStack();
    for(int i = 0; i < matrixRowSize; i++) {
        for(int j = 0; j < matrixColSize; j++) {
            if(matrix[i][j] == 0) {
                pushStack(s , i, j);
            }
        }
    }
    
    while(!isEmpty(s)) {
        Node *n = popStack(s);
        //row fixed
        for(int i = 0; i < matrixColSize; i++) {
            matrix[n->row][i] = 0;
        }
        //col fixed
        for(int i = 0; i < matrixRowSize; i++) {
            matrix[i][n->col] = 0;
        }
    }
}
