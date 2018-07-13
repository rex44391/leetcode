typedef struct record {
    struct ListNode *p_record;
    struct record *next;
} Record;

struct ListNode *detectCycle(struct ListNode *head) {
    while(!head) return NULL;
    
    if(!head) return false;
    struct ListNode *ln = head;
    Record *r_head = NULL;
    struct ListNode *flag = NULL;
    while(ln) {
        Record **r_ptr = &r_head;
        while(*r_ptr) {
            if((*r_ptr)->p_record == ln) {
                flag = ln;
                break;
            }            
            r_ptr = &((*r_ptr)->next);
        }
        if(flag) {
            break;
        } else {
            Record *r = (Record*)malloc(sizeof(Record));
            r->p_record = ln;
            r->next = NULL;
            *r_ptr = r;
        }
        
        ln = ln->next;
    }
    return flag;
}
