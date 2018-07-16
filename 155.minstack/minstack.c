typedef struct {
    int *data;
    int maxSize;
    int min;
    int top;
} MinStack;

/** initialize your data structure here. */
MinStack* minStackCreate(int maxSize) {
    MinStack *ms = (MinStack*)malloc(sizeof(MinStack));
    ms->data = (int*)malloc(sizeof(int) * maxSize);
    ms->maxSize = maxSize;
    ms->min = INT_MAX;
    ms->top = -1;
    return ms;
}

void minStackPush(MinStack* obj, int x) {
    if(obj->top + 1 >= obj->maxSize)
        return;
    obj->top++;
    obj->data[obj->top] = x;
    if(x < obj->min)
        obj->min = x;
}

void minStackPop(MinStack* obj) {
    if(obj->top < 0) return;
    if(obj->data[obj->top] == obj->min) {
        obj->top--;
        int temp = INT_MAX;
        for(int i = 0; i <= obj->top; i++) {
            if(obj->data[i] < temp)
                temp = obj->data[i];
        }
        obj->min = temp;
    } else {
        obj->top--;
    }
}

int minStackTop(MinStack* obj) {
    if(obj->top < 0) return NULL;
    return obj->data[obj->top];
}

int minStackGetMin(MinStack* obj) {
    if(obj->top < 0) return NULL;
    return obj->min;
}

void minStackFree(MinStack* obj) {
    free(obj->data);
    free(obj);
}

