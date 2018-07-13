typedef struct node {
    int x;
    int y;
    struct node *prev;
} Node;

Node *getNode(int x, int y) {
    Node *n = (Node*)malloc(sizeof(Node));
    n->x = x;
    n->y = y;
    n->prev = NULL;
    return n;
}

typedef struct stack {
    Node *top;
} Stack;

Stack *getStack() {
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->top = NULL;
    return s;
}

void pushStack(Stack *s, int x, int y) {
    Node *n = getNode(x, y);
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



int numIslands(char** grid, int gridRowSize, int gridColSize) {
    int counter = 0;
    for(int i = 0; i < gridRowSize; i++) {
        for(int j = 0; j < gridColSize; j++) {
            if(grid[i][j] == '1') {
                counter++;
                Stack *s = getStack();
                pushStack(s, i, j);
                while(!isEmpty(s)) {
                    Node *n = popStack(s);
                    int x = n->x;
                    int y = n->y;
                    grid[x][y] = 'a';
                    
                    //test up
                    if( (x - 1) >= 0 && grid[x - 1][y] == '1')
                        pushStack(s, x - 1, y);
                    
                    //test left
                    if( (y - 1) >= 0 && grid[x][y - 1] == '1')
                        pushStack(s, x, y - 1);
                    
                    //test right
                    if( (y + 1) < gridColSize && grid[x][y + 1] == '1')
                        pushStack(s, x, y + 1);
                    
                    //test down
                    if( (x + 1) < gridRowSize && grid[x + 1][y] == '1')
                        pushStack(s, x + 1, y);
                }
                
                free(s);
            }
        }
        
    }
    return counter;
}
