struct ListNode* swapPairs(struct ListNode* head) {
    if(!head) return NULL;
    
    struct ListNode *ptr1 = head;
    struct ListNode *ptr2 = ptr1->next;
    if(!ptr2) return head;
    struct ListNode *next = ptr2->next;
    
    ptr2->next = ptr1;
    ptr1->next = next;
    head = ptr2;
    
    
    while(next) {
        struct ListNode *prev = ptr1;
        ptr1 = next;
        ptr2 = ptr1->next;
        if(!ptr2)
            break;
        
        next = ptr2->next;
        ptr2->next = ptr1;
        ptr1->next = next;
        prev->next = ptr2;
    }
    return head;
}
