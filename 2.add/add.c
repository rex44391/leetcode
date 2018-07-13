/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stddef.h>
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {    
    struct ListNode *re_head = NULL;
    struct ListNode **re_ptr = &(re_head);
    
    struct ListNode *l1_ptr = l1;
    struct ListNode *l2_ptr = l2;
    //copy l1
    struct ListNode *ln;
    while(l1_ptr) {
        ln = (struct ListNode*)malloc(sizeof(struct ListNode)); 
        ln->val = l1_ptr->val;
        ln->next = NULL;
        (*re_ptr) = ln;
        re_ptr = &(ln->next);
        l1_ptr = l1_ptr->next;
    } 
    
    
    re_ptr = &(re_head);
    int carry = 0;
    int sum;
    while(l2_ptr) {
        if(! (*re_ptr) ) {
            ln = (struct ListNode*)malloc(sizeof(struct ListNode));
            ln->val = 0;
            ln->next = NULL;
            *re_ptr = ln;
        }
        
        sum = (*re_ptr)->val + l2_ptr->val + carry;
        (*re_ptr)->val =  sum % 10;
        carry = sum / 10;
        
        re_ptr = &((*re_ptr)->next);
        l2_ptr = l2_ptr->next;
    }
    
    if(carry) {
        if(!(*re_ptr)) {
            ln = (struct ListNode*)malloc(sizeof(struct ListNode));
            ln->val = 1;
            ln->next = NULL;
            *re_ptr = ln;
        } else {
            while(carry > 0) {
                 if(!(*re_ptr)) {
                     ln = (struct ListNode*)malloc(sizeof(struct ListNode));
                     ln->val = 1;
                     ln->next = NULL;
                     *re_ptr = ln;
                     carry = 0;
                 } else {
                    sum = (*re_ptr)->val + carry;
                    (*re_ptr)->val =  sum % 10;
                    carry = sum / 10;
                    re_ptr = &((*re_ptr)->next);
                 }
            }
        }
    }
    
    return re_head;
}
