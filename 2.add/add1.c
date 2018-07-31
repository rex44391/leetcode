/*
* This version makes the code less verbose.
*/

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    if(!l1 && !l2) return NULL;
    if(!l1) return l2;
    if(!l2) return l1;
    
    int carry = 0;
    struct ListNode *ptr1 = l1;
    struct ListNode *ptr2 = l2;
    struct ListNode *re_head;
    struct ListNode **ptr = &re_head;
    
    while(ptr1 || ptr2 || carry > 0) {
        
        int temp = 0;
        if(ptr1)
            temp += ptr1->val;
        if(ptr2)
            temp += ptr2->val;
        temp += carry;
        carry = temp / 10;
        
        (*ptr) = malloc(sizeof(struct ListNode));
        (*ptr)->val = temp % 10;
        
        (*ptr)->next = NULL;
        
        ptr = &((*ptr)->next);
        
        if(ptr1)
            ptr1 = ptr1->next;
        if(ptr2)
            ptr2 = ptr2->next;
    }

    return re_head;
}
