typedef struct record {
    struct RandomListNode *in_address;
    struct RandomListNode *out_address;
} Record;

struct RandomListNode *copyRandomList(struct RandomListNode *head) {
    if(!head) return;
    
    struct RandomListNode *re = NULL;
    struct RandomListNode *ptr = head;
    struct RandomListNode **pptr = &re;
    int counter = 0;
    while(ptr) {
        counter++;
        struct RandomListNode *rln = (struct RandomListNode *)malloc(sizeof(struct RandomListNode));
        rln->label = ptr->label;
        rln->next = ptr->next;
        rln->random = NULL;
        *pptr = rln;
        pptr = &((*pptr)->next);
        ptr = ptr->next;
    }
    
    Record *r = (Record*)malloc(sizeof(Record) *counter);
    ptr = head;
    struct RandomListNode *ptr2 = re;
    for(int i = 0; i < counter; i++) {
        r[i].in_address = ptr;
        r[i].out_address = ptr2;
        ptr = ptr->next;
        ptr2 = ptr2->next;
    }
    
    ptr = head;
    ptr2 = re;
    
    while(ptr) {
        if(ptr->random) {
            for(int i = 0; i < counter;i ++) {
                if(r[i].in_address == ptr->random) {
                    ptr2->random = r[i].out_address;
                    break;
                }
            }
        }
        
        
        ptr2= ptr2->next;
        ptr = ptr->next;
    }
    
    return re;
}
